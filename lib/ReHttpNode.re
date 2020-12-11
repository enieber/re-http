open Method;

type port = int;

let start = (~routers, ~port) => {
    let app = Http.createServer((~request, ~response) => Routers.start(~request, ~response, ~routers));
    
    Log.renderRouters(routers);
    
    Http.Server.(app |> listen(~port=port));
    
    print_endline("server running in localhost:"++Js.Int.toString(port));
}
