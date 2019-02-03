type action =
  | UpdatePath(list(string));
type state = {path: list(string)};

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  initialState: () => {
    path: ReasonReact.Router.dangerouslyGetInitialUrl().path,
  },
  reducer: (action, _state) => {
    switch (action) {
    | UpdatePath(path) => ReasonReact.Update({path: path})
    };
  },
  didMount: self => {
    let watcherID =
      ReasonReact.Router.watchUrl(url => self.send(UpdatePath(url.path)));
    self.onUnmount(() => ReasonReact.Router.unwatchUrl(watcherID));
  },
  render: self => {
    <Page path={self.state.path}>
      {switch (self.state.path) {
       | ["resources"] => <Resources />
       | _ => <Landing />
       }}
    </Page>;
  },
};
