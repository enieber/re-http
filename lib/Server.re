let server =
Http.createServer((~request, ~response) => App.start(~request, ~response));

Http.Server.(server |> listen(~port=3000));
