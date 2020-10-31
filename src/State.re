type phase =
  | Work
  | Play;

type state = {
  currentPhase: phase,
  isTicking: bool,
  playTime: int,
  seconds: int,
  session: int,
  maxSessions: int,
  workTime: int,
};

type action =
  | Start
  | Stop
  | Reset
  | Tick
  | TogglePhase
  | SetTime(phase, int);

let initialState = {
  currentPhase: Work,
  isTicking: false,
  maxSessions: 4,
  playTime: 5,
  seconds: 25,
  session: 1,
  workTime: 25,
};

let reducer = (state, action) =>
  switch (action) {
  | Start => {...state, isTicking: true}
  | Stop => {...state, isTicking: false}
  | Tick =>
    if (state.seconds > 1) {
      if (state.isTicking) {
        {...state, seconds: state.seconds - 1};
      } else {
        state;
      };
    } else {
      switch (state.currentPhase) {
      | Work => {
          ...state,
          currentPhase: Play,
          seconds: state.playTime,
          isTicking: false,
        }
      | Play => {
          ...state,
          currentPhase: Work,
          seconds: state.workTime,
          session: state.session == state.maxSessions ? 1 : state.session + 1,
          isTicking: false,
        }
      };
    }
  | Reset =>
    switch (state.currentPhase) {
    | Work => {...state, seconds: state.workTime, isTicking: false}
    | Play => {...state, seconds: state.playTime, isTicking: false}
    }
  | SetTime(p, t) =>
    switch (p) {
    | Work => {...state, workTime: t}
    | Play => {...state, playTime: t}
    }
  | TogglePhase =>
    switch (state.currentPhase) {
    | Work => {...state, currentPhase: Play, seconds: state.playTime}
    | Play => {...state, currentPhase: Work, seconds: state.workTime}
    }
  };
