let component = ReasonReact.statelessComponent("Link");

let make = (~href: string, ~className="", children) => {
  ...component,
  render: _self =>
    <a
      href
      className
      onClick={(event: ReactEvent.Mouse.t) => {
        ReactEvent.Mouse.preventDefault(event);
        ReasonReact.Router.push(href);
      }}>
      ...children
    </a>,
};
