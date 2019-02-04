type state = {events: array(Service.event)};

let contentWrapper =
  Css.(style([width(pct(90.0)), maxWidth(px(700)), margin(`auto)]));

let component = ReasonReact.statelessComponent("Page");
let make = (~path, children) => {
  ...component,
  render: _self =>
    <>
      <Navbar path />
      <main id="page-children" className=contentWrapper> ...children </main>
    </>,
};
