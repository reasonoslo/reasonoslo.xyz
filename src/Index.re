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
  [color(Colors.red), selector(":hover", [color(Colors.darkRed)])],
);

ReactDOMRe.renderToElementWithId(<App />, "root");
