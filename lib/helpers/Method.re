open Http;

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


type uri = string;

type request = ClientRequest.t

type response = ServerResponse.t

type action = (request, response) => unit;

type router = {
  method: method,
  uri: uri,
  action: action
}

let methodString = (methodType) => 
  switch(methodType) {
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