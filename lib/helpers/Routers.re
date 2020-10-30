open Method;

let start = (~request, ~response, ~routers) => {
  let methodHttp = getMethod(Http.ClientRequest.getMethod(request));
  let uri = Http.ClientRequest.getUrl(request);

  List.map(router => {
    let metheod = router.method
    let uriString = router.uri
    switch (methodHttp, uri) {
    | (metheod, uriString) => router.action(request, response)
    | _ => ResponseNotFound.run(request, response)
    }
  }, routers)
};