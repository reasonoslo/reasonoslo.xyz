let component = ReasonReact.statelessComponent "Resources";

let navItemStyle =
  Styles.make display::"inline-block" margin::"1rem" textDecoration::"none" () |> Styles.className;

let make ::path _children => {
  ...component,
  render: fun _self =>
    switch path {
    | "/" => <div />
    | _ =>
      <div
        className=(
          Styles.make
            position::"absolute"
            top::"0"
            left::"0"
            right::"0"
            borderBottom::"2px silver solid"
            background::"white"
            textAlign::"center"
            () |> Styles.className
        )>
        <a href="/" className=navItemStyle> (ReasonReact.stringToElement "Reason Oslo") </a>
        <a href="/resources" className=navItemStyle> (ReasonReact.stringToElement "Resources") </a>
      </div>
    }
};
