type state = {events: array(Service.event)};

let contentWrapper =
  Css.(style([width(pct(90.0)), maxWidth(px(800)), margin(`auto)]));

[@react.component]
let make = (~path, ~children) => {
  <>
    <Navbar path />
    <main id="page-children" className=contentWrapper> children </main>
  </>;
};
