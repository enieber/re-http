 let start = (~request, ~response, ~routers) => {
    let methodOfRequest = request 
        -> Http.ClientRequest.getMethod 
        -> Method.getMethod  
    
    let uriRequest = Http.ClientRequest.getUrl(request);  
    
    let methodSelected = Server.methodSelected(methodOfRequest, uriRequest, routers);

    switch (methodSelected) {
        | None => ResponseNotFound.run(request, response)
        | Some(router) => router.action(request, response)
    }
  };