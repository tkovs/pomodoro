open ReasonUIKit;

module ButtonToggle = {
  [@react.component]
  let make = (~children, ~hidden=false, ~identifier, ~onClick) =>
    <Spread
      props={
        "data-uk-toggle":
          "target: ." ++ identifier ++ ";animation: uk-animation-fade",
        "uk-tooltip": "",
      }>
      <a
        hidden
        className="uk-link-reset uk-text-small toggle-className"
        onClick>
        children
      </a>
    </Spread>;
};

[@react.component]
let make = (~identifier) => {
  let (showSettingsButton, setShowSettingsButton) =
    React.useState(() => true);

  let toggleActiveButton = _ => setShowSettingsButton(current => !current);

  <div className="uk-margin">
    <div className="uk-text-center">
      {if (showSettingsButton) {
         <ButtonToggle identifier onClick=toggleActiveButton>
           {React.string("Settings")}
         </ButtonToggle>;
       } else {
         <ButtonToggle identifier onClick=toggleActiveButton>
           <Icon icon=Icon.ArrowLeft />
           {React.string("Back to app")}
         </ButtonToggle>;
       }}
    </div>
  </div>;
};
