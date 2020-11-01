[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(State.reducer, State.initialState);

  React.useEffect0(() => {
    let timer = Js.Global.setInterval(() => dispatch(Tick), 1000);
    Some(() => Js.Global.clearInterval(timer));
  });

  let toggleIdentifier = "toggle-components";

  <>
    <div className="uk-width-medium uk-padding-small">
      <div className=toggleIdentifier>
        <Pomodoro
          seconds={state.seconds}
          currentPhase={state.currentPhase}
          session={state.session}
          maxSessions={state.maxSessions}
          playTime={state.playTime}
          workTime={state.workTime}
          isTicking={state.isTicking}
          reset={_ => dispatch(Reset)}
          stop={_ => dispatch(Stop)}
          start={_ => dispatch(Start)}
          skipTimer={_ => dispatch(SkipTimer)}
        />
      </div>
      <div className=toggleIdentifier hidden=true>
        <Settings
          workTime={state.workTime}
          playTime={state.playTime}
          setWorkTime={phase => dispatch(SetTime(Work, phase))}
          setPlayTime={phase => dispatch(SetTime(Play, phase))}
        />
      </div>
      <Toggle identifier=toggleIdentifier />
    </div>
    <div
      className="uk-position-bottom-center uk-position-small uk-visible@m uk-position-z-index">
      <Footer />
    </div>
  </>;
};
