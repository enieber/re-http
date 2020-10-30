open Log;
open Method;

let routers = [
  {
    uri: "/api/users",
    method:GET,
    action: ApiUsers.run
  },
  {
    uri: "/api",
    method:GET,
    action: ApiHome.run
  },
  {
    uri: "/",
    method: GET,
    action: PageHome.run
  },
  {
    uri: "/about",
    method: GET,
    action: PageAbout.run
  },
]

let start = (~request, ~response) => Routers.start(~request, ~response, ~routers);

renderRouters(routers);