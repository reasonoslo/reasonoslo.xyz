[@react.component]
let make = (~href: string, ~className="", ~children) => {
  <a
    href
    className
    onClick={(event: ReactEvent.Mouse.t) => {
      ReactEvent.Mouse.preventDefault(event);
      ReasonReact.Router.push(href);
    }}>
    children
  </a>;
};
