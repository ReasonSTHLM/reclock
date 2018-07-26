let payload: Model.t = {time: 1, lang: Model.En};

payload |. Model.Json.stringify |> Js.log;

ReactDOMRe.renderToElementWithId(<App />, "app");