module Landing = {
  include ReactRe.Component.JsProps;

  let name = "Landing";
  type props = {children: list ReactRe.reactElement};

  let jsPropsToReasonProps = Some (fun jsProps => {children: jsProps##children});
  type jsProps = Js.t {. children: list ReactRe.reactElement };

  let render {props} =>
    <Page>
      <div className=((Styles.make textAlign::"center" ()) |> Styles.className)>
        <img src="/static/logo.png" alt="Reason Oslo" width="300" />
        <header>(ReactRe.stringToElement "Reason Oslo Meetup")</header>
        <p>
          (ReactRe.stringToElement "Follow us on ")
          <a href="https://twitter.com/reasonoslo">(ReactRe.stringToElement "Twitter")</a>
          (ReactRe.stringToElement ".")
        </p>
        (ReactRe.listToElement props.children)
      </div>
    </Page>;
};

include ReactRe.CreateComponent Landing;

let createElement ::children => wrapProps {children: children} ::children;
