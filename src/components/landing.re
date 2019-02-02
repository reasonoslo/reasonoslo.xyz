let component = ReasonReact.statelessComponent("Landing");

let make = _children => {
  ...component,
  render: _self =>
    <div className=Css.(style([textAlign(center)]))>
      <img src="/static/logo.png" alt="Reason Oslo" width="300" />
      <header className=Css.(style([fontSize(rem(2.))]))>
        {ReasonReact.string("Reason Oslo Meetup")}
      </header>
      <p>
        {ReasonReact.string("Follow us on ")}
        <a href="https://twitter.com/reasonoslo">
          {ReasonReact.string("Twitter")}
        </a>
        {ReasonReact.string(", and")}
        <br />
        {ReasonReact.string("join the conversation at ")}
        <br />
        <a href="https://spectrum.chat/reason-oslo">
          {ReasonReact.string("spectrum.chat/reason-oslo")}
        </a>
        {ReasonReact.string(".")}
      </p>
      <p>
        <a href="/resources">
          {ReasonReact.string("Good reason resources")}
        </a>
      </p>
    </div>,
};

let jsComponent =
  ReasonReact.wrapReasonForJs(~component, _jsProps => make([||]));
