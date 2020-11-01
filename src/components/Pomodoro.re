open ReasonUIKit;
open State;

[@react.component]
let make =
    (
      ~seconds,
      ~currentPhase,
      ~session,
      ~maxSessions,
      ~playTime,
      ~workTime,
      ~isTicking,
      ~reset,
      ~stop,
      ~start,
      ~skipTimer,
    ) =>
  <>
    <div className="uk-text-center uk-margin">
      <Timer seconds />
      {switch (currentPhase) {
       | Work => React.string("Focus")
       | Play => React.string("Break")
       }}
      <div className="uk-text-meta">
        {let session = string_of_int(session);
         let sessions = string_of_int(maxSessions);
         React.string(session ++ "/" ++ sessions)}
      </div>
    </div>
    <div
      className="uk-child-width-1-3 uk-padding-large uk-padding-remove-top uk-padding-remove-bottom">
      {let disabled =
         switch (currentPhase, seconds) {
         | (Play, seconds) => seconds == playTime
         | (Work, seconds) => seconds == workTime
         };

       <Button style=Button.StyleLink onClick=reset disabled>
         <Icon icon=Icon.Refresh />
       </Button>}
      {if (isTicking) {
         <Button style=Button.StyleLink size=Button.SizeSmall onClick=stop>
           <Icon icon=Icon.Nut ratio=2 />
         </Button>;
       } else {
         <Button style=Button.StyleLink onClick=start>
           <Icon icon=Icon.Play ratio=2 />
         </Button>;
       }}
      <Button style=Button.StyleLink onClick=skipTimer>
        <Icon icon=Icon.ArrowRight />
      </Button>
    </div>
  </>;