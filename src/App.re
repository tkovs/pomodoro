[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(State.reducer, State.initialState);

  React.useEffect0(() => {
    let timer = Js.Global.setInterval(() => dispatch(Tick), 1000);
    Some(() => Js.Global.clearInterval(timer));
  });

  <div className="uk-container uk-flex uk-flex-center">
    <div className="uk-card uk-card-default uk-card-body uk-width-1-3">
      <h3 className="uk-card-title uk-text-center">
        {React.string("Pomodoro")}
      </h3>
      <Timer seconds={state.seconds} />
      <div className="uk-container">
        <button
          className="uk-button uk-button-primary uk-width-1-3"
          onClick={_ => dispatch(Start)}>
          {React.string("Start")}
        </button>
        <button
          className="uk-button uk-button-danger uk-width-1-3"
          onClick={_ => dispatch(Stop)}>
          {React.string("Stop")}
        </button>
        <button
          className="uk-button uk-button-secondary uk-width-1-3"
          onClick={_ => dispatch(Reset)}>
          {React.string("Reset")}
        </button>
      </div>
      <div className="uk-margin-top">
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
