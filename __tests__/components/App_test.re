open Jest;
open JestDom;
open ReactTestingLibrary;

describe("Pomodoro application", () => {
  test("should render on initial state", () => {
    <App /> |> render |> container |> Expect.expect |> Expect.toMatchSnapshot
  });

  test("should run timer after click on play button", () => {
    Jest.useFakeTimers();

    let result = <App /> |> render;

    result
    |> getByTestId(~matcher=`Str("timer"))
    |> expect
    |> toHaveTextContent(`Str("20:00"))
    |> ignore;

    act(() => Jest.advanceTimersByTime(300 * 1000));

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

    act(() => Jest.advanceTimersByTime(300 * 1000));

    result
    |> getByTestId(~matcher=`Str("timer"))
    |> expect
    |> toHaveTextContent(`Str("15:00"))
    |> ignore;

    result |> container |> Expect.expect |> Expect.toMatchSnapshot;
  });

  test("should enable reset button after the first second", () => {
    Jest.useFakeTimers();

    let result = <App /> |> render;

    act(() =>
      result
      |> getByTestId(~matcher=`Str("play"))
      |> FireEvent.click
      |> ignore
    );

    result
    |> getByTestId(~matcher=`Str("reset"))
    |> expect
    |> not_
    |> toBeEnabled
    |> ignore;

    act(() => Jest.advanceTimersByTime(500));

    result
    |> getByTestId(~matcher=`Str("reset"))
    |> expect
    |> not_
    |> toBeEnabled
    |> ignore;

    act(() => Jest.advanceTimersByTime(500));

    result
    |> getByTestId(~matcher=`Str("reset"))
    |> expect
    |> toBeEnabled
    |> ignore;

    result |> container |> Expect.expect |> Expect.toMatchSnapshot;
  });

  test("should disable reset button after reset the pomodoro", () => {
    Jest.useFakeTimers();

    let result = <App /> |> render;

    act(() =>
      result
      |> getByTestId(~matcher=`Str("play"))
      |> FireEvent.click
      |> ignore
    );

    result
    |> getByTestId(~matcher=`Str("reset"))
    |> expect
    |> not_
    |> toBeEnabled
    |> ignore;

    act(() => Jest.advanceTimersByTime(1000));

    result
    |> getByTestId(~matcher=`Str("reset"))
    |> expect
    |> toBeEnabled
    |> ignore;

    act(() =>
      result
      |> getByTestId(~matcher=`Str("reset"))
      |> FireEvent.click
      |> ignore
    );

    result
    |> getByTestId(~matcher=`Str("reset"))
    |> expect
    |> not_
    |> toBeEnabled
    |> ignore;

    result |> container |> Expect.expect |> Expect.toMatchSnapshot;
  });

  test("should reset timer after click on reset button", () => {
    Jest.useFakeTimers();

    let result = <App /> |> render;

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

    act(() => Jest.advanceTimersByTime(100 * 1000));

    result
    |> getByTestId(~matcher=`Str("timer"))
    |> expect
    |> toHaveTextContent(`Str("18:20"))
    |> ignore;

    act(() =>
      result
      |> getByTestId(~matcher=`Str("reset"))
      |> FireEvent.click
      |> ignore
    );

    result
    |> getByTestId(~matcher=`Str("timer"))
    |> expect
    |> toHaveTextContent(`Str("20:00"))
    |> ignore;

    result |> container |> Expect.expect |> Expect.toMatchSnapshot;
  });

  test("should pause timer after click on pause button", () => {
    Jest.useFakeTimers();

    let result = <App /> |> render;

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

    act(() => Jest.advanceTimersByTime(10 * 1000));

    result
    |> getByTestId(~matcher=`Str("timer"))
    |> expect
    |> toHaveTextContent(`Str("19:50"))
    |> ignore;

    act(() => Jest.advanceTimersByTime(10 * 1000));

    result
    |> getByTestId(~matcher=`Str("timer"))
    |> expect
    |> toHaveTextContent(`Str("19:40"))
    |> ignore;

    act(() =>
      result
      |> getByTestId(~matcher=`Str("pause"))
      |> FireEvent.click
      |> ignore
    );

    act(() => Jest.advanceTimersByTime(10 * 1000));

    result
    |> getByTestId(~matcher=`Str("timer"))
    |> expect
    |> toHaveTextContent(`Str("19:40"))
    |> ignore;

    result |> container |> Expect.expect |> Expect.toMatchSnapshot;
  });
});
