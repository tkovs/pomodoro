[@react.component]
let make = () =>{
  let (state, dispatch) = React.useReducer(State.reducer, State.initialState);

  React.useEffect0(() => {
    let timer = Js.Global.setInterval(() => dispatch(Tick), 200)
    Some(() => Js.Global.clearInterval(timer));
  });

  <div>
    <Timer seconds={state.seconds} />
    <button onClick={_ => dispatch(Stop)}>{React.string("Stop")}</button>
    <button onClick={_ => dispatch(Start)}>{React.string("Start")}</button>
    <button onClick={_ => dispatch(Reset)}>{React.string("Reset")}</button>
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
}