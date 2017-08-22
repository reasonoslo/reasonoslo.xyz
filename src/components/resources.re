let component = ReasonReact.statelessComponent "Resources";

let make _children => {
  ...component,
  render: fun () _self =>
    <div className=((Styles.make textAlign::"left" border::"3px dashed" padding::"20px" margin::"140px" ()) |> Styles.className)>
      <h1>(ReactRe.stringToElement "Good Resources")</h1>
      <ul>
        <li>
          <a href="https://reasonml.github.io/">(ReactRe.stringToElement "Reason documentation")</a>
        </li>
        <li>
          <a href="https://reasonml.github.io/guide/editor-tools/global-installation">
            (ReactRe.stringToElement "Tool installation")
          </a>
        </li>
        <li>
          <a href="https://reasonml.github.io/guide/javascript/syntax-cheatsheet">
            (ReactRe.stringToElement "Syntax cheatsheet")
          </a>
        </li>
      </ul>
      <strong>
        <a href="https://jaredforsyth.com/">(ReactRe.stringToElement "Jared Forsyths blog")</a>
      </strong>
      <ul>
        <li>
          <a href="https://jaredforsyth.com/2017/07/05/a-reason-react-tutorial/">
            (ReactRe.stringToElement "A ReasonReact Tutorial")
          </a>
        </li>
        <li>
          <a href="https://jaredforsyth.com/2017/06/17/your-first-native-reason-ocaml-project/">
            (ReactRe.stringToElement "Your first native Reason/OCaml project")
          </a>
        </li>
      </ul>
    </div>
};
