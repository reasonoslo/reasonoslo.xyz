let component = ReasonReact.statelessComponent("NextEvent");

let make = (~upcomingEvents, _children) => {
  ...component,
  render: _self =>
    <div
      className=Css.(
        style([
          background(rgb(240, 240, 240)),
          position(fixed),
          bottom(rem(0.)),
          left(rem(0.)),
          right(rem(0.)),
          padding(rem(2.)),
        ])
      )>
      <div className=Css.(style([fontSize(rem(2.))]))>
        {ReasonReact.string("Next event")}
      </div>
      {switch (upcomingEvents) {
       | [||] => ReasonReact.string("Next event is not scheduled yet.")
       | _ =>
         let event: Service.event = upcomingEvents[0];
         <div>
           {ReasonReact.string(event.name)}
           <div className=Css.(style([color(gray)]))>
             {ReasonReact.string(Date.localeSting(event.time))}
           </div>
         </div>;
       }}
    </div>,
};
