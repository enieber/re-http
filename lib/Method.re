type method =
    GET
    | POST
    | PUT
    | UPDATE
    | DELETE
    | HEAD
    | OPTION
    | CONNECT
    | TRACE
    | PATCH

let methodString = (method) => 
    switch(method) {
        | GET => "GET"
        | POST => "POST"
        | PUT => "PUT"
        | UPDATE => "UPDATE"
        | DELETE => "DELETE"
        | HEAD => "HEAD"
        | OPTION => "OPTION"
        | CONNECT => "CONNECT"
        | TRACE => "TRACE"
        | PATCH => "PATCH"
}

let getMethod = (method) => {
    switch(method) {
        | `GET => GET
        | `POST => POST
        | `PUT => PUT
        | `UPDATE => UPDATE
        | `DELETE => DELETE
        | `HEAD => HEAD
        | `OPTION => OPTION
        | `CONNECT => CONNECT
        | `TRACE => TRACE
        | `PATCH => PATCH
    }
}