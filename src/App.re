open ReasonUIKit;

[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(State.reducer, State.initialState);

  React.useEffect0(() => {
    let timer = Js.Global.setInterval(() => dispatch(Tick), 1000);
    Some(() => Js.Global.clearInterval(timer));
  });

  <div className="uk-flex uk-flex-center uk-flex-middle uk-height-viewport">
    <div className="uk-position-top"> <Title /> </div>
    <div className="uk-card uk-card-default uk-card-body">
      <h3 className="uk-card-title uk-text-center">
        {switch (state.currentPhase) {
         | Work => React.string("Focus")
         | Play => React.string("Break")
         }}
      </h3>
      <Timer seconds={state.seconds} />
      <div className="button-group uk-child-width-1-3">
        {if (state.isTicking) {
           <Button style=Button.StyleDanger onClick={_ => dispatch(Stop)}>
             <Icon icon=Icon.Ban />
           </Button>;
         } else {
           <Button style=Button.StylePrimary onClick={_ => dispatch(Start)}>
             <Icon icon=Icon.PlayCircle />
           </Button>;
         }}
        {let disabled =
           switch (state.currentPhase, state.seconds) {
           | (Play, seconds) => seconds == state.playTime
           | (Work, seconds) => seconds == state.workTime
           };

         <Button
           style=Button.StyleSecondary
           onClick={_ => dispatch(Reset)}
           disabled>
           <Icon icon=Icon.Refresh />
         </Button>}
        <Button style=Button.StyleLink onClick={_ => dispatch(SkipTimer)}>
          <Icon icon=Icon.Home />
        </Button>
      </div>
      <div className="uk-text-meta uk-text-center">
        {let session = string_of_int(state.session);
         let sessions = string_of_int(state.maxSessions);
         React.string(session ++ "/" ++ sessions)}
      </div>
      <div>
        <EditPhaseTime
          phase="Work"
          value={state.workTime}
          onChange={e => dispatch(SetTime(Work, e))}
        />
        <EditPhaseTime
          phase="Play"
          value={state.playTime}
          onChange={e => dispatch(SetTime(Play, e))}
        />
      </div>
    </div>
  </div>;
};
