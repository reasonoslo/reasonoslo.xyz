let string = ReasonReact.string;

type events = array(Service.event);
type state = {events};
type action =
  | Receive(events);

let component = ReasonReact.reducerComponent("NextEvent");
let make = _children => {
  ...component,
  initialState: () => {events: [||]},
  reducer: (action, _state) => {
    switch (action) {
    | Receive(events) => ReasonReact.Update({events: events})
    };
  },
  didMount: self => {
    let _ =
      Js.Promise.(
        Service.fetchNextEvents()
        |> then_(events => self.send(Receive(events)) |> resolve)
      );
    ();
  },
  render: self =>
    <div>
      <div className=Css.(style([fontSize(rem(2.))]))>
        {string("Next event")}
      </div>
      {switch (self.state.events) {
       | [||] => string("Next event is not scheduled yet.")
       | _ =>
         let event: Service.event = self.state.events[0];
         <div>
           <a href={event.url}> {string(event.name)} </a>
           <div className=Css.(style([color(gray)]))>
             {string(Date.localeSting(event.time))}
           </div>
         </div>;
       }}
    </div>,
};
