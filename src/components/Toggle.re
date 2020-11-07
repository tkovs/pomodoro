open ReasonUIKit;

module ButtonToggle = {
  [@react.component]
  let make = (~children, ~identifier, ~onClick, ~tooltip="", ~disabled=false) =>
    <Spread
      props={
        "data-uk-toggle":
          "target: ." ++ identifier ++ ";animation: uk-animation-fade",
        "uk-tooltip": tooltip,
      }>
      <button
        className="uk-button uk-button-text toggle-className" onClick disabled>
        children
      </button>
    </Spread>;
};

[@react.component]
let make = (~identifier, ~isReseted) => {
  let (showSettingsButton, setShowSettingsButton) =
    React.useState(() => true);

  let toggleActiveButton = _ => setShowSettingsButton(current => !current);

  let settingsTooltip =
    !isReseted ? "Reset the app to enable the settings button" : "";

  <div className="uk-margin">
    <div className="uk-text-center">
      {if (showSettingsButton) {
         <ButtonToggle
           identifier
           onClick=toggleActiveButton
           tooltip=settingsTooltip
           disabled={!isReseted}>
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
