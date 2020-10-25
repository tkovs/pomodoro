type state = {
  seconds: int,
  isTicking: bool
};

type action =
  | Start
  | Stop
  | Reset
  | Tick;

let initialState = {
  seconds: 30,
  isTicking: false,
};

let reducer = (state, action) =>
  switch action {
  | Start => { ...state, isTicking: true }
  | Stop => { ...state, isTicking: false }
  | Reset => { ...state, seconds: 30 }
  | Tick =>
    if (state.isTicking && state.seconds > 0) {
      { ...state, seconds: state.seconds - 1 }
    } else {
      state
    }
  };
