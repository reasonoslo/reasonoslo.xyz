open Constants;
let string = ReasonReact.string;

let wrapper =
  Css.(
    style([
      display(`flex),
      flexDirection(`column),
      lineHeight(em(1.4)),
      maxWidth(pct(90.)),
      fontSize(em(1.2)),
      paddingTop(rem(2.)),
      margin(`auto),
      media(
        Media.large,
        [fontSize(em(1.4)), flexDirection(`row), padding(rem(2.))],
      ),
    ])
  );

let nextEventWrapper =
  Css.(
    style([width(pct(100.)), media(Media.large, [width(pct(45.))])])
  );

[@react.component]
let make = () => {
  <div className=wrapper>
    <div>
      <p>
        {string("Follow us on ")}
        <a href="https://twitter.com/reasonoslo"> {string("Twitter")} </a>
        {string(", and ")}
        {string("join the conversation at ")}
        <br />
        <a
          href="https://join.slack.com/t/reasonoslo/shared_invite/enQtNjc4MTU1NTQ0ODg2LWNjMGYyZGU3ODQ3Yzc0OGI3YWQ4NjAzY2MxMmU0NzM4YmRlMWYxYWFiMmZhMjU5MWM4MjhhZmViZDFlNjIxOTc">
          {string("reasonoslo.slack.com")}
        </a>
        {string(".")}
      </p>
      <p>
        <Link href="/resources"> {string("Good reason resources")} </Link>
      </p>
    </div>
    <div className=nextEventWrapper> <NextEvent /> </div>
  </div>;
};
