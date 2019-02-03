let string = ReasonReact.string;

let component = ReasonReact.statelessComponent("Landing");
let make = _children => {
  ...component,
  render: _self =>
    <div
      className=Css.(
        style([
          fontSize(em(1.4)),
          lineHeight(em(1.4)),
          padding(em(4.)),
          textAlign(center),
        ])
      )>
      <p>
        {string("Follow us on ")}
        <a href="https://twitter.com/reasonoslo"> {string("Twitter")} </a>
        {string(", and ")}
        {string("join the conversation at ")}
        <a href="https://spectrum.chat/reason-oslo">
          {string("spectrum.chat/reason-oslo")}
        </a>
        {string(".")}
      </p>
      <p>
        <Link href="/resources"> {string("Good reason resources")} </Link>
      </p>
    </div>,
};
