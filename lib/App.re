open Http;

let start = (~request, ~response) => {
  let methodHttp = ClientRequest.getMethod(request);
  let uri = ClientRequest.getUrl(request);

  switch (methodHttp, uri) {
  | (`GET, "/") => PageHome.run(request, response)
  | (`GET, "/about") => PageAbout.run(request, response)
  | (`GET, "/api") => ApiHome.run(request, response)
  | (`GET, "/api/users") => ApiUsers.run(request, response)

  | _ => Rest.bodyResponse(response, 404, "File not Found")
  };
};

print_endline("server running in localhost:3000");
