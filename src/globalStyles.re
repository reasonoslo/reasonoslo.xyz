/* Global styles */
let red = "#cf5342";

let styles = [
  ("html", Styles.make ()),
  (
    "body",
    Styles.make
      color::"#222222"
      display::"flex"
      fontFamily::"sans-serif"
      justifyContent::"center"
      marginTop::"3em"
      fontSize::"18px"
      lineHeight::"1.45"
      ()
  ),
  ("a", Styles.make color::"black" ())
];

/* Resets: based off https://bulma.io */
let resets = [
  /* Blocks */
  ("html,body,h1,h2,h3", Styles.make margin::"0" padding::"0" ()),
  /* Headings */
  ("h1,h2,h3", Styles.make fontWeight::"normal" ()),
  /* Form */
  ("button", Styles.make margin::"0" ()),
  /* Box sizing */
  ("html", Styles.make boxSizing::"inherit" ()),
  ("*,*:after,*:before", Styles.make boxSizing::"border-box" ())
];

let () = List.iter Styles.style (resets @ styles);
