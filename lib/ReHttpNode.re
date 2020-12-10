open Http;
open Log;
open Method;

type port = int;

let start = (~routers, ~port) => {
    let server = createServer((~request, ~response) => Routers.start(~request, ~response, ~routers));
    Server.(server |>listen(~port=port));
    renderRouters(routers);
    print_endline("server running in localhost:"++Js.Int.toString(port));
}
