open Jest;
open Expect;
open ReasonHooksTestingLibrary.Testing;

type useReducer = {
  state: State.state,
  dispatch: State.action => unit,
};

let useReducer = (~initialState) => {
  let (state, dispatch) = React.useReducer(State.reducer, initialState);
  {state, dispatch};
};

describe("State.useReducer", () => {
  open Result;
  open State;

  describe("initial state", () => {
    test("should start with initial state", () => {
      let initialState: State.state = {
        currentPhase: Work,
        isTicking: false,
        maxSessions: 4,
        playTime: 5 * 60,
        seconds: 20 * 60,
        session: 1,
        workTime: 20 * 60,
      };

      let container = renderHook(() => useReducer(~initialState), ());

      expect(container->result->current.state) |> toEqual(initialState);
    })
  });

  describe("Play action", () => {
    test("should active isTicking after dispatch a Play", () => {
      let initialState = {
        currentPhase: Work,
        isTicking: false,
        maxSessions: 4,
        playTime: 5 * 60,
        seconds: 20 * 60,
        session: 1,
        workTime: 20 * 60,
      };
      let newState: State.state = {...initialState, isTicking: true};
      let container = renderHook(() => useReducer(~initialState), ());

      expect(container->result->current.state)
      |> toEqual(initialState)
      |> ignore;
      act(() => container->result->current.dispatch(State.Start));
      expect(container->result->current.state) |> toEqual(newState);
    })
  });

  describe("Stop action", () => {
    test("should disable isTicking after dispatch a Stop", () => {
      let initialState = {
        currentPhase: Work,
        isTicking: true,
        maxSessions: 4,
        playTime: 5 * 60,
        seconds: 20 * 60,
        session: 1,
        workTime: 20 * 60,
      };
      let newState: State.state = {...initialState, isTicking: false};
      let container = renderHook(() => useReducer(~initialState), ());

      expect(container->result->current.state)
      |> toEqual(initialState)
      |> ignore;
      act(() => container->result->current.dispatch(State.Stop));
      expect(container->result->current.state) |> toEqual(newState);
    })
  });

  describe("Tick action", () => {
    test(
      "with seconds higher than 1 and isTicking true, should decrement 1 second",
      () => {
      let initialState = {
        currentPhase: Work,
        isTicking: true,
        maxSessions: 4,
        playTime: 5 * 60,
        seconds: 10,
        session: 1,
        workTime: 20 * 60,
      };
      let newState: State.state = {...initialState, seconds: 9};
      let container = renderHook(() => useReducer(~initialState), ());

      expect(container->result->current.state)
      |> toEqual(initialState)
      |> ignore;
      act(() => container->result->current.dispatch(State.Tick));
      expect(container->result->current.state) |> toEqual(newState);
    });

    test(
      "with seconds higher than 1 and isTicking false, should return the same state",
      () => {
      let initialState = {
        currentPhase: Work,
        isTicking: false,
        maxSessions: 4,
        playTime: 5 * 60,
        seconds: 10,
        session: 1,
        workTime: 20 * 60,
      };
      let container = renderHook(() => useReducer(~initialState), ());

      expect(container->result->current.state)
      |> toEqual(initialState)
      |> ignore;
      act(() => container->result->current.dispatch(State.Tick));
      expect(container->result->current.state) |> toEqual(initialState);
    });

    test(
      "with seconds not higher than 1 and current phase Work, should update state according",
      () => {
        let initialState = {
          currentPhase: Work,
          isTicking: true,
          maxSessions: 4,
          playTime: 5,
          seconds: 1,
          session: 1,
          workTime: 20,
        };
        let newState: State.state = {
          ...initialState,
          isTicking: false,
          seconds: initialState.playTime,
          currentPhase: State.Play,
        };
        let container = renderHook(() => useReducer(~initialState), ());

        expect(container->result->current.state)
        |> toEqual(initialState)
        |> ignore;
        act(() => container->result->current.dispatch(State.Tick));
        expect(container->result->current.state) |> toEqual(newState);
      },
    );

    test(
      "with seconds not higher than 1 and current phase Play, should update state according",
      () => {
        let initialState = {
          currentPhase: Play,
          isTicking: true,
          maxSessions: 4,
          playTime: 5,
          seconds: 1,
          session: 1,
          workTime: 20,
        };
        let newState: State.state = {
          ...initialState,
          isTicking: false,
          seconds: initialState.workTime,
          currentPhase: State.Work,
          session: 2,
        };
        let container = renderHook(() => useReducer(~initialState), ());

        expect(container->result->current.state)
        |> toEqual(initialState)
        |> ignore;
        act(() => container->result->current.dispatch(State.Tick));
        expect(container->result->current.state) |> toEqual(newState);
      },
    );

    test(
      "with seconds not higher than 1 and current phase Play and session on max, should update state according",
      () => {
        let initialState = {
          currentPhase: Play,
          isTicking: true,
          maxSessions: 4,
          playTime: 5,
          seconds: 1,
          session: 4,
          workTime: 20,
        };
        let newState: State.state = {
          ...initialState,
          isTicking: false,
          seconds: initialState.workTime,
          currentPhase: State.Work,
          session: 1,
        };
        let container = renderHook(() => useReducer(~initialState), ());

        expect(container->result->current.state)
        |> toEqual(initialState)
        |> ignore;
        act(() => container->result->current.dispatch(State.Tick));
        expect(container->result->current.state) |> toEqual(newState);
      },
    );
  });

  describe("Reset action", () => {
    test(
      "on Work phase, should stop ticking and reset seconds to workTime", () => {
      let initialState = {
        currentPhase: Work,
        isTicking: true,
        maxSessions: 4,
        playTime: 5,
        seconds: 17,
        session: 1,
        workTime: 20,
      };
      let newState: State.state = {
        ...initialState,
        isTicking: false,
        seconds: initialState.workTime,
      };
      let container = renderHook(() => useReducer(~initialState), ());

      expect(container->result->current.state)
      |> toEqual(initialState)
      |> ignore;
      act(() => container->result->current.dispatch(State.Reset));
      expect(container->result->current.state) |> toEqual(newState);
    });

    test(
      "on Play phase, should stop ticking and reset seconds to playTime", () => {
      let initialState = {
        currentPhase: Play,
        isTicking: true,
        maxSessions: 4,
        playTime: 15,
        seconds: 7,
        session: 1,
        workTime: 20,
      };
      let newState: State.state = {
        ...initialState,
        isTicking: false,
        seconds: initialState.playTime,
      };
      let container = renderHook(() => useReducer(~initialState), ());

      expect(container->result->current.state)
      |> toEqual(initialState)
      |> ignore;
      act(() => container->result->current.dispatch(State.Reset));
      expect(container->result->current.state) |> toEqual(newState);
    });
  });

  describe("SkipTimer", () => {
    test("on Work phase, should should update state according", () => {
      let initialState = {
        currentPhase: Work,
        isTicking: true,
        maxSessions: 4,
        playTime: 5,
        seconds: 20,
        session: 1,
        workTime: 20,
      };
      let newState: State.state = {
        ...initialState,
        currentPhase: Play,
        seconds: initialState.playTime,
        isTicking: false,
      };
      let container = renderHook(() => useReducer(~initialState), ());

      expect(container->result->current.state)
      |> toEqual(initialState)
      |> ignore;
      act(() => container->result->current.dispatch(State.SkipTimer));
      expect(container->result->current.state) |> toEqual(newState);
    });

    test(
      "on Play phase and not last session, should should update state according",
      () => {
      let initialState = {
        currentPhase: Play,
        isTicking: true,
        maxSessions: 4,
        playTime: 5,
        seconds: 20,
        session: 1,
        workTime: 20,
      };
      let newState: State.state = {
        ...initialState,
        currentPhase: Work,
        seconds: initialState.workTime,
        isTicking: false,
        session: initialState.session + 1,
      };
      let container = renderHook(() => useReducer(~initialState), ());

      expect(container->result->current.state)
      |> toEqual(initialState)
      |> ignore;
      act(() => container->result->current.dispatch(State.SkipTimer));
      expect(container->result->current.state) |> toEqual(newState);
    });

    test(
      "on Play phase and last session, should should update state according",
      () => {
      let initialState = {
        currentPhase: Play,
        isTicking: true,
        maxSessions: 4,
        playTime: 5,
        seconds: 20,
        session: 4,
        workTime: 20,
      };
      let newState: State.state = {
        ...initialState,
        currentPhase: Work,
        seconds: initialState.workTime,
        isTicking: false,
        session: 1,
      };
      let container = renderHook(() => useReducer(~initialState), ());

      expect(container->result->current.state)
      |> toEqual(initialState)
      |> ignore;
      act(() => container->result->current.dispatch(State.SkipTimer));
      expect(container->result->current.state) |> toEqual(newState);
    });
  });
});
