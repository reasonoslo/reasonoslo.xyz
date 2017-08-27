let localeSting: float => string = [%bs.raw
  {| function (date) { return new Date(date).toLocaleString() } |}
];
