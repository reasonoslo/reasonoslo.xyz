let component = ReasonReact.statelessComponent "NextEvent";

let make ::upcomingEvents _children => {
  ...component,
  render: fun _self =>
    <div
      className=(
        Styles.make
          background::"#f0f0f0"
          position::"fixed"
          bottom::"0"
          left::"0"
          right::"0"
          padding::"2rem"
          () |> Styles.className
      )>
      <div className=(Styles.make fontSize::"3rem" () |> Styles.className)>
        (ReasonReact.stringToElement "Next event")
      </div>
      (
        switch upcomingEvents {
        | [||] => ReasonReact.stringToElement "Next event is not scheduled yet."
        | _ =>
          let event: Service.event = upcomingEvents.(0);
          <div>
            (ReasonReact.stringToElement event.name)
            <div className=(Styles.make color::"gray" () |> Styles.className)>
              (ReasonReact.stringToElement (Date.localeSting event.time))
            </div>
          </div>
        }
      )
    </div>
};
