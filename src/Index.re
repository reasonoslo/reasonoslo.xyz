open Css;

global("*,*:after,*:before", [boxSizing(borderBox)]);

global(
  "body",
  [
    margin(px(0)),
    display(`flex),
    justifyContent(center),
    marginTop(rem(3.)),
    marginBottom(rem(10.)),
    fontSize(px(18)),
    fontFamily("sans-serif"),
    lineHeight(em(1.45)),
  ],
);

global(
  "a",
  [color(Colors.reason), selector(":hover", [color(Colors.darkReason)])],
);

ReactDOMRe.renderToElementWithId(<App />, "root");
