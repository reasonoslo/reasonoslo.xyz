open Css;

global("*,*:after,*:before", [boxSizing(borderBox)]);

global(
  "body",
  [
    margin(px(0)),
    padding(px(0)),
    display(`flex),
    justifyContent(center),
    fontSize(px(18)),
    fontFamily("sans-serif"),
    lineHeight(em(1.45)),
  ],
);

global("#root", [width(pct(100.)), margin(px(0))]);

global("p", [marginTop(rem(0.))]);

global(
  "a",
  [
    color(Colors.red),
    hover([color(Colors.darkRed)]),
    focus([
      padding(px(-6)),
      padding(px(6)),
      outline(px(0), solid, rgba(0, 0, 0, 0.)),
      background(Colors.darkRed),
      color(rgb(240, 240, 240)),
      borderBottom(px(3), solid, Colors.darkRed),
      zIndex(10),
      textDecoration(none),
    ]),
    selector(":hover:focus", [textDecoration(underline)]),
  ],
);

ReactDOMRe.renderToElementWithId(<App />, "root");
