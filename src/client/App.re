type state = {response: option(string)};

type action =
  | FetchedResponse(string);

let component = ReasonReact.reducerComponent("Page");

type response;

[@bs.val] external fetch : string => Js.Promise.t(response) = "fetch";

[@bs.send] external text : response => Js.Promise.t(string) = "text";

let make = (~message, _children) => {
  ...component,
  initialState: () => {response: None},
  reducer: (action, state) =>
    switch (action) {
    | FetchedResponse(r) => ReasonReact.Update({response: Some(r)})
    },
  didMount: self => {
    let handleLoadedModel = m => self.send(FetchedResponse(m));
    fetch("http://localhost:2112")
    |> Js.Promise.then_(response => {
         Js.log(response);
         text(response);
       })
    |> Js.Promise.then_(string => {
         Js.log(string);
         self.send(FetchedResponse(string));
         Js.Promise.resolve();
       })
    |> ignore;
  },
  render: self => {
    let response =
      switch (self.state.response) {
      | Some(response) => response
      | None => "loading..."
      };
    <div>
      <h1> (ReasonReact.string(message)) </h1>
      <div> (ReasonReact.string(response)) </div>
    </div>;
  },
};