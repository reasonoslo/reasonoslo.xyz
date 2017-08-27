type state = {events: array Service.event};

let component = ReasonReact.statefulComponent "Page";

let handleResponse events _self => ReasonReact.Update {events: events};

let make children => {
  ...component,
  initialState: fun () => {events: [||]},
  didMount: fun self => {
    Js.Promise.(
      Service.fetchNextEvents () |>
      then_ (fun events => self.update handleResponse events |> resolve)
    );
    ReasonReact.NoUpdate
  },
  render: fun self =>
    <div>
      (ReasonReact.arrayToElement children)
      <NextEvent upcomingEvents=self.state.events />
    </div>
};

let jsComponent = ReasonReact.wrapReasonForJs ::component (fun jsProps => make jsProps##children);
