type state = {events: array(Service.event)};

let component = ReasonReact.statelessComponent("Page");

let handleResponse = (events, _self) => ReasonReact.Update({events: events});

let make = (~path, children) => {
  ...component,
  render: _self =>
    <> <Navbar path /> <main id="page-children"> ...children </main> </>,
};
