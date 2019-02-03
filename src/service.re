open Bs_fetch;
type event = {
  id: string,
  name: string,
  description: string,
  time: float,
  url: string,
};

let parseEvent = (json: Js.Json.t) =>
  Json.Decode.{
    id: json |> field("id", string),
    name: json |> field("name", string),
    description: json |> field("description", string),
    time: json |> field("time", float),
    url: json |> field("event_url", string),
  };

let parseEvents = (json: Js.Json.t) => Json.Decode.(array(parseEvent, json));

let fetchNextEvents = () =>
  Js.Promise.(
    fetch("/.netlify/functions/events/upcoming")
    |> then_(Response.json)
    |> then_(result =>
         Json.Decode.(result |> field("events", parseEvents)) |> resolve
       )
  );
