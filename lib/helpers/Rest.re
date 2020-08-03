open Http;

let bodyResponse = (response, statusCode, message) => {
  ServerResponse.(
    response |> setStatusCode(statusCode) |> write(message) |> end_
  );
};

let bodyJsonResponse = (response, statusCode, message) => {
  ServerResponse.(
    response
    |> setHeader("content-type", "application/json")
    |> setStatusCode(statusCode)
    |> write(message)
    |> end_
  );
};
