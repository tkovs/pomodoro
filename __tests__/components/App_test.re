open Jest;
open JestDom;
open ReactTestingLibrary;

describe("Pomodoro application", () => {
  test("should render on initial state", () => {
    <App /> |> render |> container |> Expect.expect |> Expect.toMatchSnapshot
  });

  Skip.test("should run timer after click on play button", () => {
    let result = <App /> |> render;

    Jest.useFakeTimers();

    result
    |> getByTestId(~matcher=`Str("reset"))
    |> expect
    |> toBeDisabled
    |> ignore;

    result
    |> getByTestId(~matcher=`Str("timer"))
    |> expect
    |> toHaveTextContent(`Str("20:00"))
    |> ignore;

    act(() =>
      result
      |> getByTestId(~matcher=`Str("play"))
      |> FireEvent.click
      |> ignore
    );

    act(() => Jest.runTimersToTime(3000));
    result |> rerender(<App />);

    result
    |> getByTestId(~matcher=`Str("timer"))
    |> expect
    |> toHaveTextContent(`Str("19:57"));
  });
});
