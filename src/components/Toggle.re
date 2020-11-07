open ReasonUIKit;

module ButtonToggle = {
  [@react.component]
  let make = (~children, ~identifier, ~onClick, ~disabled=false, ~testId) => {
    let props = {
      "data-uk-toggle":
        "target: ." ++ identifier ++ ";animation: uk-animation-fade",
      "data-testid": testId,
    };

    <Spread props>
      <button
        className="uk-button uk-button-text toggle-className" onClick disabled>
        children
      </button>
    </Spread>;
  };
};

[@react.component]
let make = (~identifier, ~isReseted, ~nonValidTime, ~onBackToApp) => {
  let (showSettingsButton, setShowSettingsButton) =
    React.useState(() => true);

  let toggleActiveButton = _ => setShowSettingsButton(current => !current);

  <div className="uk-margin">
    <div className="uk-text-center">
      {if (showSettingsButton) {
         <ButtonToggle
           testId="go-to-settings"
           identifier
           onClick=toggleActiveButton
           disabled={!isReseted}>
           {React.string("Settings")}
         </ButtonToggle>;
       } else {
         <ButtonToggle
           identifier
           onClick={_ => {
             onBackToApp();
             toggleActiveButton();
           }}
           testId="back-to-app"
           disabled=nonValidTime>
           <Icon icon=Icon.ArrowLeft />
           {React.string("Back to app")}
         </ButtonToggle>;
       }}
    </div>
  </div>;
};
