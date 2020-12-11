open Http;

type method =
    GET
    | POST
    | PUT
    | UPDATE
    | DELETE
    | HEAD
    | OPTION
    | CONNECT
    | TRACE
    | PATCH

type uri = string;

type request = ClientRequest.t

type response = ServerResponse.t

type action = (request, response) => unit;

type router = {
    method: method,
    uri: uri,
    action: action
};

module Rest {

    let bodyResponse = (response, statusCode, message) => {
        ServerResponse.(
            response 
            |> setStatusCode(statusCode) 
            |> write(message) 
            |> end_
        );
    };

    let bodyJsonResponse = (response, statusCode, message) => {
        ServerResponse.(
            response
            |> setHeader("content-type", "application/json")
            |> setStatusCode(statusCode)
            |> write(message)
            |> end_
        );
    };
}

module ResponseNotFound {
    let run = (_, response) => {
        Rest.bodyResponse(response, 404, "File not Found")
    }
}

module Method {

    let methodString = (methodType) => 
        switch(methodType) {
            | GET => "GET"
            | POST => "POST"
            | PUT => "PUT"
            | UPDATE => "UPDATE"
            | DELETE => "DELETE"
            | HEAD => "HEAD"
            | OPTION => "OPTION"
            | CONNECT => "CONNECT"
            | TRACE => "TRACE"
            | PATCH => "PATCH"
    }

    let getMethod = (method) => {
        switch(method) {
            | `GET => GET
            | `POST => POST
            | `PUT => PUT
            | `UPDATE => UPDATE
            | `DELETE => DELETE
            | `HEAD => HEAD
            | `OPTION => OPTION
            | `CONNECT => CONNECT
            | `TRACE => TRACE
            | `PATCH => PATCH
        }
    }
}

module Routers {

  let start = (~request, ~response, ~routers) => {
    let methodHttp = Method.getMethod(Http.ClientRequest.getMethod(request));
    let uri = Http.ClientRequest.getUrl(request);

    List.map(router => {
      let metheod = router.method
      let uriString = router.uri
      if (metheod == methodHttp && uri == uriString)  {
        router.action(request, response)
      }
    }, routers)
  };
}

module Log {

    let transformTring = (method) => Js.String.make(method)

    let renderRouterItem = (method, uri) => {
        print_endline(Method.methodString(method) ++ ": " ++ uri)
    }

    let renderRouters = (routers) => {
        List.map(router => renderRouterItem(router.method, router.uri), routers);
    }
}

module Server {
    type port = int;

    let start = (~routers, ~port) => {
        let app = Http.createServer((~request, ~response) => {
            Routers.start(~request, ~response, ~routers)
        });
        
        Log.renderRouters(routers);
        
        Http.Server.(app |> listen(~port=port));
        
        print_endline("server running in localhost:"++Js.Int.toString(port));
    }
}