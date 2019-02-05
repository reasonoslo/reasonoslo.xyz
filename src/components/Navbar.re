open Constants;
let navbarStyle = Css.(style([background(Colors.red), textAlign(center)]));

let landingHeaderStyle =
  Css.(
    style([
      display(`flex),
      flexDirection(`column),
      minHeight(pct(50.)),
      alignItems(`center),
      justifyContent(`center),
      media(
        Media.large,
        [
          flexDirection(`row),
          justifyContent(`flexStart),
          alignItems(`flexEnd),
        ],
      ),
    ])
  );

let navItemStyle =
  Css.(
    style([
      display(inlineBlock),
      margin(rem(1.)),
      color(rgb(240, 240, 240)),
      textDecoration(none),
      borderBottom(px(2), solid, rgba(0, 0, 0, 0.)),
      lineHeight(em(0.98)),
      hover([
        color(rgb(240, 240, 240)),
        borderBottom(px(2), solid, Colors.darkRed),
      ]),
    ])
  );

let string = ReasonReact.string;

let component = ReasonReact.statelessComponent("Resources");
let make = (~path: list(string), _children) => {
  ...component,
  render: _self => {
    <div className={Css.merge([navbarStyle])}>
      <div
        className=Css.(
          merge([
            style([maxWidth(px(800)), margin(`auto)]),
            List.length(path) == 0 ? landingHeaderStyle : "",
          ])
        )>
        {switch (path) {
         | [] =>
           <>
             <img
               src="/static/logo.png"
               alt="Reason Oslo"
               className=Css.(style([width(px(300)), height(px(300))]))
             />
             <header
               className=Css.(
                 style([
                   fontSize(rem(2.)),
                   paddingBottom(px(24)),
                   color(white),
                 ])
               )>
               {ReasonReact.string("Reason Oslo Meetup")}
             </header>
           </>
         | _ =>
           <>
             <Link href="/" className=navItemStyle>
               {string("Reason Oslo")}
             </Link>
             <Link href="/resources" className=navItemStyle>
               {string("Resources")}
             </Link>
           </>
         }}
      </div>
    </div>;
  },
};
