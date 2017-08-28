let component = ReasonReact.statefulComponent "Landing";

let make _children => {
  ...component,
  render: fun _self =>
    <Page path="/">
      <div className=(Styles.make textAlign::"center" () |> Styles.className)>
        <img src="/static/logo.png" alt="Reason Oslo" width="300" />
        <header className=(Styles.make fontSize::"2rem" () |> Styles.className)>
          (ReasonReact.stringToElement "Reason Oslo Meetup")
        </header>
        <p>
          (ReasonReact.stringToElement "Follow us on ")
          <a href="https://twitter.com/reasonoslo"> (ReasonReact.stringToElement "Twitter") </a>
          (ReasonReact.stringToElement ", and")
          <br />
          (ReasonReact.stringToElement "join the conversation at ")
          <br />
          <a href="https://spectrum.chat/reason-oslo">
            (ReasonReact.stringToElement "spectrum.chat/reason-oslo")
          </a>
          (ReasonReact.stringToElement ".")
        </p>
        <p> <a href="/resources"> (ReasonReact.stringToElement "Good reason resources") </a> </p>
      </div>
    </Page>
};

let jsComponent = ReasonReact.wrapReasonForJs ::component (fun _jsProps => make [||]);
