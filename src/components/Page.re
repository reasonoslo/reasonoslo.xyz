module Page = {
  include ReactRe.Component;

  let name = "Page";
  type props = {children: list ReactRe.reactElement};

  let render {props} =>
    <div>
      (ReactRe.listToElement props.children)
    </div>;
};

include ReactRe.CreateComponent Page;

let createElement ::children => wrapProps {children: children} ::children;
