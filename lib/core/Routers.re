open Method;

let start = (~request, ~response, ~routers) => {
  let methodHttp = getMethod(Http.ClientRequest.getMethod(request));
  let uri = Http.ClientRequest.getUrl(request);

  List.map(router => {
    let metheod = router.method
    let uriString = router.uri
    if (metheod == methodHttp && uri == uriString)  {
      router.action(request, response)
    }
  }, routers)
};