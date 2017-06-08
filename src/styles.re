/* import glamor */
external glamor : 'glamor = "glamor" [@@bs.module];

/* glamor helpers based off https://github.com/wyze/reason-calculator */

let make = ReactDOMRe.Style.make;

/* Glamor helpers */
let global tag styles => glamor##css##global tag styles;
let insert styles => glamor##css##insert styles;
let className styles => glamor##css styles;
let active styles => glamor##active styles;
let hover styles => glamor##hover styles;

/* Empty */
let empty: string = className (make ());

/* 'a -> bool */
let removeEmpty style => style != empty;

/* option string -> list 'a -> string */
let merge ::separator=" " lstStyles =>
  lstStyles
    |> List.filter removeEmpty
    |> Array.of_list
    |> Array.map Js.String.make
    |> Js.Array.joinWith separator;

/* Style helper */
let style ( tag, styles ) => global tag styles;
let media mq => insert mq;
