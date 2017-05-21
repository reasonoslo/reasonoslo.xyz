module IndexPage = {
  include ReactRe.Component;

  let name = "IndexPage";
  type props = {message: string};

  let render {props} =>
    <div>
      <img src="logo.png" width="300px" alt="Reason Oslo" />
      <header>(ReactRe.stringToElement "Reason Oslo Meetup")</header>
      <p>
        (ReactRe.stringToElement "Follow us on ")
        <a href="https://twitter.com/reasonoslo">(ReactRe.stringToElement "Twitter")</a>(ReactRe.stringToElement ".")</p>
    </div>;
};

include ReactRe.CreateComponent IndexPage;

let createElement ::message => wrapProps {message: message};
