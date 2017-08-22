let component = ReasonReact.statelessComponent "Page";

let make children => {
  ...component,
  render: fun _self => <div> (ReasonReact.arrayToElement children) </div>
};
