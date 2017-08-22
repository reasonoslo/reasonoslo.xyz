let component = ReasonReact.statelessComponent "Resources";

let make _children => {
  ...component,
  render: fun _self =>
    <div
      className=(
        Styles.make
          textAlign::"left"
          border::"3px dashed"
          padding::"20px"
          margin::"140px"
          () |> Styles.className
      )>
      <h1> (ReasonReact.stringToElement "Good Resources") </h1>
      <ul>
        <li>
          <a href="https://reasonml.github.io/">
            (ReasonReact.stringToElement "Reason documentation")
          </a>
        </li>
        <li>
          <a
            href="https://reasonml.github.io/guide/editor-tools/global-installation">
            (ReasonReact.stringToElement "Tool installation")
          </a>
        </li>
        <li>
          <a
            href="https://reasonml.github.io/guide/javascript/syntax-cheatsheet">
            (ReasonReact.stringToElement "Syntax cheatsheet")
          </a>
        </li>
      </ul>
      <strong>
        <a href="https://jaredforsyth.com/">
          (ReasonReact.stringToElement "Jared Forsyths blog")
        </a>
      </strong>
      <ul>
        <li>
          <a
            href="https://jaredforsyth.com/2017/07/05/a-reason-react-tutorial/">
            (ReasonReact.stringToElement "A ReasonReact Tutorial")
          </a>
        </li>
        <li>
          <a
            href="https://jaredforsyth.com/2017/06/17/your-first-native-reason-ocaml-project/">
            (
              ReasonReact.stringToElement "Your first native Reason/OCaml project"
            )
          </a>
        </li>
      </ul>
    </div>
};
