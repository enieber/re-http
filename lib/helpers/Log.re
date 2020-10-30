open Http;
open Method;

let transformTring = (method) => Js.String.make(method)

let renderRouterItem = (method, uri) => {
    print_endline(methodString(method) ++ ": " ++ uri)
}

let renderRouters = (routers) => {
    List.map(router => renderRouterItem(router.method, router.uri), routers);
}