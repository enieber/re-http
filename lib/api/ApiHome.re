type jsonResponse = {
  status: bool,
  message: string,
};

module Encode = {
  let jsonResponse = c => {
    Json.Encode.(
      object_([
        ("status", bool(c.status)),
        ("message", string(c.message)),
      ])
    );
  };
};

let run = (request, response) => {
  let data = {| {
      "status": true,
      "message": "Bem vindo"
    } |};

  let statusApi = data |> Json.parseOrRaise;

  Rest.bodyJsonResponse(response, 200, Js.Json.stringify(statusApi));
};
