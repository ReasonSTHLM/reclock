type language =
  | En
  | De
  | Es;

[@bs.deriving abstract]
type jsT = {
  time: int,
  lang: string,
};

type t = {
  time: int,
  lang: language,
};

let language_to_str = (lang: language) : string =>
  switch (lang) {
  | En => "En"
  | Es => "Es"
  | De => "De"
  };

let language_of_str =
  fun
  | "DE" => De
  | "ES" => Es
  | _ => En;

let t_to_jsT = (t: t) : jsT =>
  jsT(~time=t.time, ~lang=language_to_str(t.lang));

let jsT_to_t = (jsT: jsT) : t => {
  time: time(jsT),
  lang: language_of_str(lang(jsT)),
};

/*
 let foo: t = {time: 1, lang: En};

 let bar: jsT = t_to_jsT(foo);

 Js.log(bar); */
[@bs.scope "JSON"] [@bs.val]
external __unsafe_stringify : 't => string = "stringify";

[@bs.scope "JSON"] [@bs.val] external __unsafe_parse : string => 't = "parse";

module Json = {
  let stringify = (t: t) : string => __unsafe_stringify(t_to_jsT(t));
  let parse = (s: string) : t => jsT_to_t(__unsafe_parse(s));
};

module Payload = {
  [@bs.deriving abstract]
  type payload = {
    time: int,
    lang: string,
  };
  let from_t = t => payload(~time=t.time, ~lang=language_to_str(t.lang));
  let to_t = payload => {
    time: time(payload),
    lang: language_of_str @@ lang @@ payload,
  };
};