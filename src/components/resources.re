open Constants;
let string = ReasonReact.string;

type link = {
  url: string,
  title: string,
  published: option(string),
};

let links = [|
  {
    url: "https://reasonml.github.io/",
    title: "Reason documentation",
    published: None,
  },
  {
    url: "https://reasonml.github.io/docs/en/editor-plugins",
    title: "Editor plugins",
    published: None,
  },
  {
    url: "https://reasonml.github.io/docs/en/syntax-cheatsheet.html",
    title: "Syntax cheatsheet",
    published: None,
  },
  {
    url: "https://reasonml.github.io/reason-react/",
    title: "Reason react documentation",
    published: None,
  },
  {
    url: "https://github.com/vramana/awesome-reasonml",
    title: "Awesome reasonml",
    published: None,
  },
  {
    url: "https://redex.github.io/",
    title: "Redex: package index",
    published: None,
  },
  {
    url: "https://github.com/ostera/reason-design-patterns",
    title: "Reason design patterns",
    published: None,
  },
  {
    url: "https://github.com/bsansouci/Bucklescript",
    title: "Bucklescript native",
    published: None,
  },
  {
    url: "https://github.com/Artris/algorithms",
    title: "Algorithms in reason",
    published: None,
  },
|];

let videos = [|
  {
    url: "https://egghead.io/courses/get-started-with-reason",
    title: "Get Started with Reason - egghead.io course",
    published: None,
  },
|];

let books = [|
  {
    url: "http://reasonmlhub.com/exploring-reasonml/",
    title: "Exploring ReasonML and functional programming",
    published: None,
  },
|];

let articles = [|
  {
    url: "https://rolflekang.com/creating-a-cli-with-reason-native",
    title: "Creating a CLI with Reason native",
    published: Some("12.02.2019"),
  },
  {
    url: "https://jamesfriend.com.au/a-first-reason-react-app-for-js-developers",
    title: "A First ReasonReact app for Javascript developers",
    published: Some("14.11.2017"),
  },
  {
    url: "https://jaredforsyth.com/2017/07/05/a-reason-react-tutorial/",
    title: "A ReasonReact Tutorial",
    published: Some("05.06.2017"),
  },
  {
    url: "https://jaredforsyth.com/2017/06/17/your-first-native-reason-ocaml-project/",
    title: "Your first native Reason/OCaml project",
    published: Some("17.05.2017"),
  },
|];

let array = (fn, items) => {
  items |> Array.map(fn) |> ReasonReact.array;
};

let renderLinks =
  array(({url, title, published}) =>
    <li key=url>
      <a href=url> {string(title)} </a>
      {switch (published) {
       | Some(value) => <> <br /> {string("Published " ++ value)} </>
       | None => ReasonReact.null
       }}
    </li>
  );

let component = ReasonReact.statelessComponent("Resources");
let make = _children => {
  ...component,
  render: _self =>
    <div className=Css.(style([textAlign(`left)]))>
      <h1> {string("Good Resources")} </h1>
      <p>
        {string(
           "This page contains links to a few good resources "
           ++ "like documentation and getting started tutorials.",
         )}
      </p>
      <ul
        className=Css.(
          style([
            marginBottom(rem(2.)),
            media(Media.large, [columnCount(`count(2))]),
          ])
        )>
        {renderLinks(links)}
      </ul>
      <h2> {string("Articles")} </h2>
      <ul> {renderLinks(articles)} </ul>
      <h2> {string("Videos")} </h2>
      <ul> {renderLinks(videos)} </ul>
      <h2> {string("Books")} </h2>
      <ul> {renderLinks(books)} </ul>
    </div>,
};
