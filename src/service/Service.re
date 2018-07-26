type server;

type http;

type req;

type res;

[@bs.send] external write : (res, string) => unit = "write";

[@bs.send] external end_ : res => unit = "end";

[@bs.send] external setHeader : (res, string, string) => unit = "setHeader";

type handler = (req, res) => unit;

[@bs.module "http"] external createServer : handler => server = "createServer";

[@bs.send] external listen : (server, int, string => unit) => unit = "listen";

let payload: Model.t = {time: 1, lang: Model.En};

let handler = (_req, res) => {
  Js.log("Sending you stuff...");
  res |. setHeader("Access-Control-Allow-Origin", "*");
  payload |. Model.Json.stringify |> write(res);
  res |. end_;
  Js.log("Done! Yes!");
  ();
};

createServer(handler) |. listen(2112, _error => Js.log("Running..."));