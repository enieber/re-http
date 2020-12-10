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

ReHttpNode.strat(routers, 3000)