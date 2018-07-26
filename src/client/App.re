/*
  CODE FOR FRONTEND GOES HERE.

  Assignment:
  Create a react component which queries the backend on http://localhost:2112
  and displays the response in the form: "Today is the {date}".
  The language should depend on the lang parameter sent in the response.

  En: "Today is the {data}"
  De: "Heute ist der {date}"
  Es: "Hoy es el {date}"

  After building and starting the backend and webserver, you can see your
  frontend on http://localhost:8080/src/client/
 */
let component = ReasonReact.statelessComponent("App");

let make = _children => {...component, render: _self => <div />};