let component = ReasonReact.statelessComponent "Landing";

let make _children => {
  ...component,
  render: fun () _self =>
    <Page>
      <div className=((Styles.make textAlign::"center" ()) |> Styles.className)>
        <img src="/static/logo.png" alt="Reason Oslo" width="300" />
        <header>(ReactRe.stringToElement "Reason Oslo Meetup")</header>
        <p>
          (ReactRe.stringToElement "Follow us on ")
          <a href="https://twitter.com/reasonoslo">(ReactRe.stringToElement "Twitter")</a>
          (ReactRe.stringToElement ".")
        </p>
      </div>
    </Page>
};

let jsComponent = ReasonReact.wrapReasonForJs ::component (fun _jsProps => make [||]);
