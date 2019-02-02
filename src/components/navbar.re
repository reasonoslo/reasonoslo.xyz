let navbarStyle =
  Css.(
    style([
      position(absolute),
      top(rem(0.)),
      left(rem(0.)),
      right(rem(0.)),
      background(Colors.reason),
      textAlign(center),
    ])
  );

let navItemStyle =
  Css.(
    style([
      display(inlineBlock),
      margin(rem(1.)),
      color(rgb(240, 240, 240)),
      textDecoration(none),
    ])
  );

let string = ReasonReact.string;

let component = ReasonReact.statelessComponent("Resources");
let make = (~path: list(string), _children) => {
  ...component,
  render: _self => {
    switch (path) {
    | [] => <div />
    | _ =>
      <nav className=navbarStyle>
        <a href="/" className=navItemStyle> {string("Reason Oslo")} </a>
        <a href="/resources" className=navItemStyle>
          {string("Resources")}
        </a>
      </nav>
    };
  },
};
