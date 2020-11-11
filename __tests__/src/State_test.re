open Jest;
open Expect;
open ReasonHooksTestingLibrary.Testing;
open State;

type useReducer = {
  state,
  dispatch: action => unit,
};

let useReducer = () => {
  let (state, dispatch) = React.useReducer(reducer, initialState);
  {state, dispatch};
};

describe("State.useReducer", () => {
  open Result;
  test("should have an initial state", () => {
    let initialState: State.state = {
      currentPhase: Work,
      isTicking: false,
      maxSessions: 4,
      playTime: 5 * 60,
      seconds: 20 * 60,
      session: 1,
      workTime: 20 * 60,
    };

    let container = renderHook(() => useReducer(), ());

    expect(container->result->current.state) |> toEqual(initialState);
  });

  test("should active isTicking after dispatch a Play", () => {
    open State;
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
    let container = renderHook(() => useReducer(), ());

    expect(container->result->current.state)
    |> toEqual(initialState)
    |> ignore;
    act(() => container->result->current.dispatch(State.Start));
    expect(container->result->current.state) |> toEqual(newState);
  });
});
