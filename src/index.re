include Styles;
include GlobalStyles;

let app =
  <Page>
    <div className=((Styles.make textAlign::"center" ()) |> Styles.className)>
      <img src="logo.png" alt="Reason Oslo" width="300" />
      <header>(ReactRe.stringToElement "Reason Oslo Meetup")</header>
      <p>
        (ReactRe.stringToElement "Follow us on ")
        <a href="https://twitter.com/reasonoslo">(ReactRe.stringToElement "Twitter")</a>
        (ReactRe.stringToElement ".")
      </p>
    </div>
  </Page>;

ReactDOMRe.renderToElementWithClassName app "root";
