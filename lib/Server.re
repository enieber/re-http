open Http;
open Method;

type port = int;

type uri = string;

type request = ClientRequest.t

type response = ServerResponse.t

type action = (request, response) => unit;

type router = {
    method: method,
    uri: uri,
    action: action
};

let starting = (app, port) => Http.Server.(app |> listen(~port=port));

let methodSelected = (methodOfRequest, uriRequest, routers) => List.find_opt(router => {
        router.method == methodOfRequest && 
        router.uri == uriRequest
    }, routers)


let transformTring = (method) => Js.String.make(method)

let renderRouterItem = (method, uri) => {
    print_endline(Method.methodString(method) ++ ": " ++ uri)
}


let renderRouters = (routers) => {
    List.map(router => renderRouterItem(router.method, router.uri), routers);
}