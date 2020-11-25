type phase =
  | Work
  | Play

type state = {
  currentPhase: phase,
  isTicking: bool,
  playTime: int,
  seconds: int,
  session: int,
  maxSessions: int,
  workTime: int,
  naturalLeap: bool,
}

type action =
  | Start
  | Stop
  | Reset
  | Tick
  | SkipTimer
  | SetTime(phase, int)

let initialState = {
  isTicking: false,
  currentPhase: Work,
  seconds: 20 * 60,
  playTime: 5 * 60,
  workTime: 20 * 60,
  session: 1,
  maxSessions: 4,
  naturalLeap: false,
}

let reducer = (state, action) =>
  switch action {
  | Start => {...state, isTicking: true, naturalLeap: false}
  | Stop => {...state, isTicking: false}
  | Tick =>
    if state.seconds > 1 {
      if state.isTicking {
        {
          ...state,
          seconds: state.seconds - 1,
        }
      } else {
        state
      }
    } else {
      switch state.currentPhase {
      | Work => {
          ...state,
          currentPhase: Play,
          seconds: state.playTime,
          isTicking: false,
          naturalLeap: true,
        }
      | Play => {
          ...state,
          currentPhase: Work,
          seconds: state.workTime,
          session: state.session == state.maxSessions ? 1 : state.session + 1,
          isTicking: false,
          naturalLeap: true,
        }
      }
    }
  | Reset =>
    switch state.currentPhase {
    | Work => {...state, seconds: state.workTime, isTicking: false}
    | Play => {...state, seconds: state.playTime, isTicking: false}
    }
  | SetTime(p, t) =>
    switch p {
    | Work => {...state, workTime: t}
    | Play => {...state, playTime: t}
    }
  | SkipTimer => {
      ...state,
      naturalLeap: false,
      currentPhase: state.currentPhase === Play ? Work : Play,
      seconds: state.currentPhase === Play ? state.workTime : state.playTime,
      isTicking: false,
      session: if state.currentPhase === Play {
        state.session == state.maxSessions ? 1 : state.session + 1
      } else {
        state.session
      },
    }
  }
