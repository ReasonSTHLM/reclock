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

let language_to_str = (lang: language) : string => {
    switch lang {
    | En => "En"
    | Es => "Es"
    | De => "De";
    };
};

let t_to_jsT = (t: t) : jsT => {
  jsT(~time=t.time, ~lang=language_to_str(t.lang));
};

let foo: t = {time:1, lang:En};
let bar: jsT = t_to_jsT(foo);

Js.log(bar);