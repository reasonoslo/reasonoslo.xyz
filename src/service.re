open Bs_fetch;

type event = {
  id: string,
  name: string,
  description: string,
  time: float
};

let parseEvent (json: Js.Json.t) =>
  Json.Decode.{
    id: json |> field "id" string,
    name: json |> field "name" string,
    description: json |> field "description" string,
    time: json |> field "time" float
  };

let parseEvents (json: Js.Json.t) => Json.Decode.(array parseEvent json);

let fetchNextEvents () =>
  Js.Promise.(
    fetch "/api/events/upcoming" |> then_ Response.json |>
    then_ (fun result => parseEvents result |> resolve)
  );
