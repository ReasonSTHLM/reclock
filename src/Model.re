type locale =
  | DE
  | ES
  | EN;

type t = {
  time: float,
  locale: locale,
};

let locale_to_string =
  fun
  | DE => "DE"
  | ES => "ES"
  | EN => "EN";

let locale_of_string =
  fun
  | "DE" => DE
  | "ES" => ES
  | _ => EN;

[@bs.scope "JSON"] [@bs.val]
external __unsafe_stringify : 't => string = "stringify"

[@bs.scope "JSON"] [@bs.val]
external __unsafe_parse : string => 't = "parse"

module Json = {
  let stringify = __unsafe_stringify;
  let parse = __unsafe_parse;
}

module Payload = {
  [@bs.deriving abstract]
  type payload = {
    time: float,
    locale: string,
  };
  let from_t = t => payload(
    ~time= t.time,
    ~locale= locale_to_string(t.locale),
  );
  let to_t = payload => {
    time: time(payload),
    locale: locale_of_string @@ locale @@ payload,
  };
}
