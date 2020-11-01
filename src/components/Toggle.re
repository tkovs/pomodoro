open ReasonUIKit;

module ButtonToggle = {
  [@react.component]
  let make = (~children, ~hidden=false, ~identifier) =>
    <Spread
      props={
        "data-uk-toggle":
          "target: ." ++ identifier ++ ";animation: uk-animation-fade",
      }>
      <a hidden className="uk-link-reset uk-text-small toggle-className">
        children
      </a>
    </Spread>;
};

[@react.component]
let make = (~identifier) =>
  <div className="uk-margin">
    <div className="uk-text-center">
      <ButtonToggle identifier> {React.string("Settings")} </ButtonToggle>
      <ButtonToggle identifier hidden=true>
        <Icon icon=Icon.ArrowLeft />
        {React.string("Back to app")}
      </ButtonToggle>
    </div>
  </div>;
