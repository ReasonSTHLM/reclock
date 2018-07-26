let component = ReasonReact.statelessComponent("Page");

[@bs.val] external fetch : string => Js.Promise.t(string) = "fetch";

let make = (~message, _children) => {
  ...component,
  didMount: self => {
    fetch("http://localhost:2112")
    |> Js.Promise.then_(value => {
         Js.log(value);
         Js.Promise.resolve();
       });
    ();
  },
  render: self => <div> (ReasonReact.string(message)) </div>,
};