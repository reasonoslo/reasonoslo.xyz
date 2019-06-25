[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();

  <Page path={url.path}>
    {switch (url.path) {
     | ["resources"] => <Resources />
     | _ => <Landing />
     }}
  </Page>;
};
