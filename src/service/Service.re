type server;
type http;

type req;

type res;

[@bs.send]
external write : res => string => unit = "write";

[@bs.send]
external end_ : res => unit = "end";

type handler = (req, res) => unit;

[@bs.module "http"]
external createServer : handler => server = "createServer";

[@bs.send]
external listen : server => (int, string => unit) => unit = "listen";

let payload: Model.t = {
  time:1.0,
  locale:Model.EN,
};

let handler = (_req, res) => {
  Js.log("Sending you stuff...");
  payload
    |. Model.Payload.from_t
    |. Model.Json.stringify
    |. Model.Json.parse
    |. Model.Payload.to_t
    |> x => x == payload
    |> Js.log;
  payload |. Model.Payload.from_t |. Model.Json.stringify |> write(res);
  res |. end_;
  Js.log("Done!");
  ();
};

createServer(handler)
|. listen(2112, (_error) => Js.log("Running..."));
