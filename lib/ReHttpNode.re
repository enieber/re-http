open Server;

let start = (~routers, ~port) => {
    let app = Http.createServer((~request, ~response) => {
        Routers.start(~request, ~response, ~routers)
    });
    
    renderRouters(routers);
    
    print_endline("server running in localhost:"++ string_of_int(port));
}
