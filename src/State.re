type phase =
  | Work
  | Play;

type state = {
  seconds: int,
  isTicking: bool,
  workTime: int,
  playTime: int,
  currentPhase: phase,
};

type action =
  | Start
  | Stop
  | Reset
  | Tick
  | TogglePhase
  | SetTime(phase, int);

let initialState = {
  seconds: 25,
  isTicking: false,
  workTime: 25,
  playTime: 5,
  currentPhase: Work,
};

let reducer = (state, action) =>
  switch action {
  | Start => { ...state, isTicking: true }
  | Stop => { ...state, isTicking: false }
  | Tick =>
    if (state.seconds > 0) {
      if (state.isTicking) {
        { ...state, seconds: state.seconds - 1 }
      } else {
        state
      }
    } else {
      switch state.currentPhase {
      | Work => { ...state, currentPhase: Play, seconds: state.playTime }
      | Play => { ...state, currentPhase: Work, seconds: state.workTime }
      }
    }
  | Reset =>
    switch (state.currentPhase) {
    | Work => { ...state, seconds: state.workTime }
    | Play => { ...state, seconds: state.playTime }
    }
  | SetTime(p, t) =>
    switch p {
    | Work => { ...state, workTime: t }
    | Play => { ...state, playTime: t }
    }
  | TogglePhase =>
    switch state.currentPhase {
    | Work => { ...state, currentPhase: Play, seconds: state.playTime }
    | Play => { ...state, currentPhase: Work, seconds: state.workTime }
    }
  };
