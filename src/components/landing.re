type state = {events: array Service.event};

let component = ReasonReact.statefulComponent "Landing";

let handleResponse events _self => ReasonReact.Update {events: events};

let make _children => {
  ...component,
  initialState: fun () => {events: [||]},
  didMount: fun self => {
    Js.Promise.(
      Service.fetchNextEvents () |>
      then_ (fun events => (self.update handleResponse) events |> resolve)
    );
    ReasonReact.NoUpdate
  },
  render: fun self =>
    <Page>
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
          <a href="https://spectrum.chat/reason-oslo">
            (ReasonReact.stringToElement "spectrum.chat/reason-oslo")
          </a>
        </p>
      </div>
      <NextEvent upcomingEvents=self.state.events />
    </Page>
};

let jsComponent = ReasonReact.wrapReasonForJs ::component (fun _jsProps => make [||]);
