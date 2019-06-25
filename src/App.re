[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();

  <Page path={url.path}>
    {switch (url.path) {
     | ["resources"] => <Resources />
     | ["code-of-conduct"] => <CodeOfConduct />
     | _ => <Landing />
     }}
  </Page>;
};
