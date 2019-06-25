let string = ReasonReact.string;

type events = array(Service.event);

[@react.component]
let make = () => {
  let (events, setEvents) = React.useState(() => [||]);
  React.useEffect0(() => {
    let _ =
      Js.Promise.(
        Service.fetchNextEvents()
        |> then_(events => setEvents(_ => events) |> resolve)
      );
    None;
  });

  <div>
    <div className=Css.(style([fontSize(rem(2.))]))>
      {string("Next event")}
    </div>
    {switch (events) {
     | [||] => string("Next event is not scheduled yet.")
     | _ =>
       let event: Service.event = events[0];
       <div>
         <a href={event.url}> {string(event.name)} </a>
         <div className=Css.(style([color(gray)]))>
           {string(Date.localeSting(event.time))}
         </div>
       </div>;
     }}
  </div>;
};
