open Constants;
let string = ReasonReact.string;

type link = {
  url: string,
  title: string,
};

type article = {
  url: string,
  title: string,
  published: string,
};

let links = [|
  {url: "https://reasonml.github.io/", title: "Reason documentation"},
  {
    url: "https://reasonml.github.io/docs/en/editor-plugins",
    title: "Editor plugins",
  },
  {
    url: "https://reasonml.github.io/docs/en/syntax-cheatsheet.html",
    title: "Syntax cheatsheet",
  },
  {
    url: "https://reasonml.github.io/reason-react/",
    title: "Reason react documentation",
  },
  {
    url: "https://github.com/vramana/awesome-reasonml",
    title: "Awesome reasonml",
  },
  {url: "https://redex.github.io/", title: "Redex: package index"},
|];

let videos = [|
  {
    url: "https://egghead.io/courses/get-started-with-reason",
    title: "Get Started with Reason - egghead.io course",
  },
|];

let articles = [|
  {
    url: "https://rolflekang.com/creating-a-cli-with-reason-native",
    title: "Creating a CLI with Reason native",
    published: "12.02.2019",
  },
  {
    url: "https://jamesfriend.com.au/a-first-reason-react-app-for-js-developers",
    title: "A First ReasonReact app for Javascript developers",
    published: "14.11.2017",
  },
  {
    url: "https://jaredforsyth.com/2017/07/05/a-reason-react-tutorial/",
    title: "A ReasonReact Tutorial",
    published: "05.06.2017",
  },
  {
    url: "https://jaredforsyth.com/2017/06/17/your-first-native-reason-ocaml-project/",
    title: "Your first native Reason/OCaml project",
    published: "17.05.2017",
  },
|];

let array = (fn, items) => {
  items |> Array.map(fn) |> ReasonReact.array;
};

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
        {links
         |> array((link: link) =>
              <li key={link.url}>
                <a href={link.url}> {string(link.title)} </a>
              </li>
            )}
      </ul>
      <h2> {string("Articles")} </h2>
      <ul>
        {articles
         |> array(article =>
              <li key={article.url}>
                <a href={article.url}> {string(article.title)} </a>
                <br />
                {string("Published " ++ article.published)}
              </li>
            )}
      </ul>
      <h2> {string("Videos")} </h2>
      <ul>
        {videos
         |> array((video: link) =>
              <li key={video.url}>
                <a href={video.url}> {string(video.title)} </a>
              </li>
            )}
      </ul>
    </div>,
};
