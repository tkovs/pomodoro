open ReasonUIKit;

module ButtonToggle = {
  [@react.component]
  let make = (~children, ~identifier, ~onClick, ~disabled=false) => {
    let props = {
      "data-uk-toggle":
        "target: ." ++ identifier ++ ";animation: uk-animation-fade",
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
           identifier onClick=toggleActiveButton disabled={!isReseted}>
           {React.string("Settings")}
         </ButtonToggle>;
       } else {
         <ButtonToggle
           identifier
           onClick={_ => {
             onBackToApp();
             toggleActiveButton();
           }}
           disabled=nonValidTime>
           <Icon icon=Icon.ArrowLeft />
           {React.string("Back to app")}
         </ButtonToggle>;
       }}
    </div>
  </div>;
};
