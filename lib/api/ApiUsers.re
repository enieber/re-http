type jsonResponse = {
  status: bool,
  dynamics: Js.Dict.t(int),
};

module Encode = {
  let jsonResponse = c => {
    Json.Encode.(
      object_([
        ("status", bool(c.status)),
        ("dynamics", c.dynamics |> dict(int)),
      ])
    );
  };
};

let run = (_, response) => {
  let data = {| {
      "status": true,
      "dynamics": { "hello": "users", "random": 8 }
    } |};

  let statusApi = data |> Json.parseOrRaise;

  Rest.bodyJsonResponse(response, 200, Js.Json.stringify(statusApi));
};
