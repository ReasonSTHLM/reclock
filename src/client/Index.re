let payload: Model.t = {time: 1.0, locale: Model.EN};

payload |. Model.Payload.from_t |. Model.Json.stringify |> Js.log;

ReactDOMRe.renderToElementWithId(<Component1 message="Hello!" />, "index1");

ReactDOMRe.renderToElementWithId(<Component2 greeting="Hello!" />, "index2");
