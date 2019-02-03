let component = ReasonReact.statelessComponent("Resources");

let make = _children => {
  ...component,
  render: _self =>
    <div
      className=Css.(
        style([
          textAlign(`left),
          border(px(3), dashed, rgb(0, 0, 0)),
          padding(px(20)),
          margin(px(140)),
        ])
      )>
      <h1> {ReasonReact.string("Good Resources")} </h1>
      <ul>
        <li>
          <a href="https://reasonml.github.io/">
            {ReasonReact.string("Reason documentation")}
          </a>
        </li>
        <li>
          <a
            href="https://reasonml.github.io/guide/editor-tools/global-installation">
            {ReasonReact.string("Tool installation")}
          </a>
        </li>
        <li>
          <a
            href="https://reasonml.github.io/guide/javascript/syntax-cheatsheet">
            {ReasonReact.string("Syntax cheatsheet")}
          </a>
        </li>
      </ul>
      <strong>
        <a href="https://jaredforsyth.com/">
          {ReasonReact.string("Jared Forsyths blog")}
        </a>
      </strong>
      <ul>
        <li>
          <a
            href="https://jaredforsyth.com/2017/07/05/a-reason-react-tutorial/">
            {ReasonReact.string("A ReasonReact Tutorial")}
          </a>
        </li>
        <li>
          <a
            href="https://jaredforsyth.com/2017/06/17/your-first-native-reason-ocaml-project/">
            {ReasonReact.string("Your first native Reason/OCaml project")}
          </a>
        </li>
      </ul>
      <strong> {ReasonReact.string("Articles")} </strong>
      <ul>
        <li>
          <a
            href="https://jamesfriend.com.au/a-first-reason-react-app-for-js-developers">
            {ReasonReact.string(
               "A First ReasonReact app for Javascript developers",
             )}
          </a>
        </li>
      </ul>
    </div>,
};
