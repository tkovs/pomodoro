open Jest
open JestDom
open ReactTestingLibrary

describe("Pomodoro application", () => {
  describe("Initial state", () =>
    test("should render on initial state", () =>
      <App /> |> render |> container |> Expect.expect |> Expect.toMatchSnapshot
    )
  )

  describe("play feature", () => test("should run timer after click on play button", () => {
      Jest.useFakeTimers()

      let result = <App /> |> render

      result
      |> getByTestId(~matcher=#Str("timer"))
      |> expect
      |> toHaveTextContent(#Str("20:00"))
      |> ignore

      act(() => Jest.advanceTimersByTime(300 * 1000))

      result
      |> getByTestId(~matcher=#Str("timer"))
      |> expect
      |> toHaveTextContent(#Str("20:00"))
      |> ignore

      act(() => result |> getByTestId(~matcher=#Str("play")) |> FireEvent.click |> ignore)

      act(() => Jest.advanceTimersByTime(300 * 1000))

      result
      |> getByTestId(~matcher=#Str("timer"))
      |> expect
      |> toHaveTextContent(#Str("15:00"))
      |> ignore

      result |> container |> Expect.expect |> Expect.toMatchSnapshot
    }))

  describe("reset feature", () => {
    test("should enable reset button after the first second", () => {
      Jest.useFakeTimers()

      let result = <App /> |> render

      act(() => result |> getByTestId(~matcher=#Str("play")) |> FireEvent.click |> ignore)

      result |> getByTestId(~matcher=#Str("reset")) |> expect |> not__ |> toBeEnabled |> ignore

      act(() => Jest.advanceTimersByTime(500))

      result |> getByTestId(~matcher=#Str("reset")) |> expect |> not__ |> toBeEnabled |> ignore

      act(() => Jest.advanceTimersByTime(500))

      result |> getByTestId(~matcher=#Str("reset")) |> expect |> toBeEnabled |> ignore

      result |> container |> Expect.expect |> Expect.toMatchSnapshot
    })

    test("should disable reset button after reset the pomodoro", () => {
      Jest.useFakeTimers()

      let result = <App /> |> render

      act(() => result |> getByTestId(~matcher=#Str("play")) |> FireEvent.click |> ignore)

      result |> getByTestId(~matcher=#Str("reset")) |> expect |> not__ |> toBeEnabled |> ignore

      act(() => Jest.advanceTimersByTime(1000))

      result |> getByTestId(~matcher=#Str("reset")) |> expect |> toBeEnabled |> ignore

      act(() => result |> getByTestId(~matcher=#Str("reset")) |> FireEvent.click |> ignore)

      result |> getByTestId(~matcher=#Str("reset")) |> expect |> not__ |> toBeEnabled |> ignore

      result |> container |> Expect.expect |> Expect.toMatchSnapshot
    })

    test("should disable reset button after the phase ends", () => {
      Jest.useFakeTimers()

      let result = <App /> |> render

      act(() => result |> getByTestId(~matcher=#Str("play")) |> FireEvent.click |> ignore)

      result |> getByTestId(~matcher=#Str("reset")) |> expect |> toBeDisabled |> ignore

      act(() => Jest.advanceTimersByTime(10 * 60 * 1000))

      result |> getByTestId(~matcher=#Str("reset")) |> expect |> toBeEnabled |> ignore

      act(() => Jest.advanceTimersByTime(10 * 60 * 1000))

      result |> getByTestId(~matcher=#Str("reset")) |> expect |> toBeDisabled |> ignore

      result |> container |> Expect.expect |> Expect.toMatchSnapshot
    })

    test("should reset timer after click on reset button", () => {
      Jest.useFakeTimers()

      let result = <App /> |> render

      result
      |> getByTestId(~matcher=#Str("timer"))
      |> expect
      |> toHaveTextContent(#Str("20:00"))
      |> ignore

      act(() => result |> getByTestId(~matcher=#Str("play")) |> FireEvent.click |> ignore)

      act(() => Jest.advanceTimersByTime(100 * 1000))

      result
      |> getByTestId(~matcher=#Str("timer"))
      |> expect
      |> toHaveTextContent(#Str("18:20"))
      |> ignore

      act(() => result |> getByTestId(~matcher=#Str("reset")) |> FireEvent.click |> ignore)

      result
      |> getByTestId(~matcher=#Str("timer"))
      |> expect
      |> toHaveTextContent(#Str("20:00"))
      |> ignore

      result |> container |> Expect.expect |> Expect.toMatchSnapshot
    })
  })

  describe("pause feature", () => test("should pause timer after click on pause button", () => {
      Jest.useFakeTimers()

      let result = <App /> |> render

      result
      |> getByTestId(~matcher=#Str("timer"))
      |> expect
      |> toHaveTextContent(#Str("20:00"))
      |> ignore

      act(() => result |> getByTestId(~matcher=#Str("play")) |> FireEvent.click |> ignore)

      act(() => Jest.advanceTimersByTime(10 * 1000))

      result
      |> getByTestId(~matcher=#Str("timer"))
      |> expect
      |> toHaveTextContent(#Str("19:50"))
      |> ignore

      act(() => Jest.advanceTimersByTime(10 * 1000))

      result
      |> getByTestId(~matcher=#Str("timer"))
      |> expect
      |> toHaveTextContent(#Str("19:40"))
      |> ignore

      act(() => result |> getByTestId(~matcher=#Str("pause")) |> FireEvent.click |> ignore)

      act(() => Jest.advanceTimersByTime(10 * 1000))

      result
      |> getByTestId(~matcher=#Str("timer"))
      |> expect
      |> toHaveTextContent(#Str("19:40"))
      |> ignore

      result |> container |> Expect.expect |> Expect.toMatchSnapshot
    }))

  describe("phase feature", () => {
    test("should start on Focus phase, then go to Break phase", () => {
      Jest.useFakeTimers()

      let result = <App /> |> render

      act(() => result |> getByTestId(~matcher=#Str("play")) |> FireEvent.click |> ignore)

      result
      |> getByTestId(~matcher=#Str("current-phase"))
      |> expect
      |> toHaveTextContent(#Str("Focus"))
      |> ignore

      act(() => Jest.advanceTimersByTime(20 * 60 * 1000))

      result
      |> getByTestId(~matcher=#Str("current-phase"))
      |> expect
      |> toHaveTextContent(#Str("Break"))
      |> ignore

      result |> getByTestId(~matcher=#Str("play")) |> expect |> toBeInTheDocument |> ignore

      result
      |> getByTestId(~matcher=#Str("timer"))
      |> expect
      |> toHaveTextContent(#Str("05:00"))
      |> ignore

      result |> container |> Expect.expect |> Expect.toMatchSnapshot
    })

    test("should jump phase after click on jump button", () => {
      Jest.useFakeTimers()

      let result = <App /> |> render

      result
      |> getByTestId(~matcher=#Str("session"))
      |> expect
      |> toHaveTextContent(#Str("1/4"))
      |> ignore

      result
      |> getByTestId(~matcher=#Str("current-phase"))
      |> expect
      |> toHaveTextContent(#Str("Focus"))
      |> ignore

      act(() => result |> getByTestId(~matcher=#Str("jump")) |> FireEvent.click |> ignore)

      result
      |> getByTestId(~matcher=#Str("session"))
      |> expect
      |> toHaveTextContent(#Str("1/4"))
      |> ignore

      result
      |> getByTestId(~matcher=#Str("current-phase"))
      |> expect
      |> toHaveTextContent(#Str("Break"))
      |> ignore

      act(() => result |> getByTestId(~matcher=#Str("jump")) |> FireEvent.click |> ignore)

      result
      |> getByTestId(~matcher=#Str("session"))
      |> expect
      |> toHaveTextContent(#Str("2/4"))
      |> ignore

      result
      |> getByTestId(~matcher=#Str("current-phase"))
      |> expect
      |> toHaveTextContent(#Str("Focus"))
      |> ignore

      result |> container |> Expect.expect |> Expect.toMatchSnapshot
    })
  })

  describe("session feature", () => {
    test("should go to next session after the Break phase ends", () => {
      Jest.useFakeTimers()

      let result = <App /> |> render

      result
      |> getByTestId(~matcher=#Str("session"))
      |> expect
      |> toHaveTextContent(#Str("1/4"))
      |> ignore

      act(() => result |> getByTestId(~matcher=#Str("play")) |> FireEvent.click |> ignore)

      result
      |> getByTestId(~matcher=#Str("current-phase"))
      |> expect
      |> toHaveTextContent(#Str("Focus"))
      |> ignore

      act(() => Jest.advanceTimersByTime(20 * 60 * 1000))

      result
      |> getByTestId(~matcher=#Str("current-phase"))
      |> expect
      |> toHaveTextContent(#Str("Break"))
      |> ignore

      act(() => result |> getByTestId(~matcher=#Str("play")) |> FireEvent.click |> ignore)

      result
      |> getByTestId(~matcher=#Str("session"))
      |> expect
      |> toHaveTextContent(#Str("1/4"))
      |> ignore

      act(() => Jest.advanceTimersByTime(5 * 60 * 1000))

      result
      |> getByTestId(~matcher=#Str("current-phase"))
      |> expect
      |> toHaveTextContent(#Str("Focus"))
      |> ignore

      result
      |> getByTestId(~matcher=#Str("session"))
      |> expect
      |> toHaveTextContent(#Str("2/4"))
      |> ignore

      result |> container |> Expect.expect |> Expect.toMatchSnapshot
    })

    test("should back to first session after the last phase ends", () => {
      Jest.useFakeTimers()

      let result = <App /> |> render

      result
      |> getByTestId(~matcher=#Str("session"))
      |> expect
      |> toHaveTextContent(#Str("1/4"))
      |> ignore

      result
      |> getByTestId(~matcher=#Str("current-phase"))
      |> expect
      |> toHaveTextContent(#Str("Focus"))
      |> ignore

      act(() => result |> getByTestId(~matcher=#Str("jump")) |> FireEvent.click |> ignore)

      result
      |> getByTestId(~matcher=#Str("session"))
      |> expect
      |> toHaveTextContent(#Str("1/4"))
      |> ignore

      result
      |> getByTestId(~matcher=#Str("current-phase"))
      |> expect
      |> toHaveTextContent(#Str("Break"))
      |> ignore

      act(() => result |> getByTestId(~matcher=#Str("jump")) |> FireEvent.click |> ignore)

      result
      |> getByTestId(~matcher=#Str("session"))
      |> expect
      |> toHaveTextContent(#Str("2/4"))
      |> ignore

      result
      |> getByTestId(~matcher=#Str("current-phase"))
      |> expect
      |> toHaveTextContent(#Str("Focus"))
      |> ignore

      act(() => result |> getByTestId(~matcher=#Str("jump")) |> FireEvent.click |> ignore)

      result
      |> getByTestId(~matcher=#Str("session"))
      |> expect
      |> toHaveTextContent(#Str("2/4"))
      |> ignore

      result
      |> getByTestId(
        ~matcher=#Str(
          "  ������\"|>��� N���� N��@��� N���� N��@@��@������",
        ),
      )
      |> expect
      |> toHaveTextContent(#Str("Break"))
      |> ignore

      act(() => result |> getByTestId(~matcher=#Str("jump")) |> FireEvent.click |> ignore)

      result
      |> getByTestId(~matcher=#Str("session"))
      |> expect
      |> toHaveTextContent(#Str("3/4"))
      |> ignore

      result
      |> getByTestId(~matcher=#Str("current-phase"))
      |> expect
      |> toHaveTextContent(#Str("Focus"))
      |> ignore

      act(() => result |> getByTestId(~matcher=#Str("jump")) |> FireEvent.click |> ignore)

      result
      |> getByTestId(~matcher=#Str("session"))
      |> expect
      |> toHaveTextContent(#Str("3/4"))
      |> ignore

      result
      |> getByTestId(~matcher=#Str("current-phase"))
      |> expect
      |> toHaveTextContent(#Str("Break"))
      |> ignore

      act(() => result |> getByTestId(~matcher=#Str("jump")) |> FireEvent.click |> ignore)

      result
      |> getByTestId(~matcher=#Str("session"))
      |> expect
      |> toHaveTextContent(#Str("4/4"))
      |> ignore

      result
      |> getByTestId(~matcher=#Str("current-phase"))
      |> expect
      |> toHaveTextContent(#Str("Focus"))
      |> ignore

      act(() => result |> getByTestId(~matcher=#Str("jump")) |> FireEvent.click |> ignore)

      result
      |> getByTestId(~matcher=#Str("session"))
      |> expect
      |> toHaveTextContent(#Str("4/4"))
      |> ignore

      result
      |> getByTestId(~matcher=#Str("current-phase"))
      |> expect
      |> toHaveTextContent(#Str("Break"))
      |> ignore

      act(() => result |> getByTestId(~matcher=#Str("jump")) |> FireEvent.click |> ignore)

      result
      |> getByTestId(~matcher=#Str("session"))
      |> expect
      |> toHaveTextContent(#Str("1/4"))
      |> ignore

      result
      |> getByTestId(~matcher=#Str("current-phase"))
      |> expect
      |> toHaveTextContent(#Str("Focus"))
      |> ignore

      result |> container |> Expect.expect |> Expect.toMatchSnapshot
    })
  })

  describe("settings feature", () => {
    test("should disable go to settings button if the app is not reseted", () => {
      Jest.useFakeTimers()

      let result = <App /> |> render

      result |> getByTestId(~matcher=#Str("go-to-settings")) |> expect |> toBeEnabled |> ignore

      act(() => result |> getByTestId(~matcher=#Str("play")) |> FireEvent.click |> ignore)

      act(() => Jest.advanceTimersByTime(1000))

      result
      |> getByTestId(~matcher=#Str("go-to-settings"))
      |> expect
      |> not__
      |> toBeEnabled
      |> ignore

      act(() => result |> getByTestId(~matcher=#Str("reset")) |> FireEvent.click |> ignore)

      result |> getByTestId(~matcher=#Str("go-to-settings")) |> expect |> toBeEnabled |> ignore

      result |> container |> Expect.expect |> Expect.toMatchSnapshot
    })

    test("should disable back to app button if there is some input with value 0", () => {
      Jest.useFakeTimers()

      let result = <App /> |> render

      act(() => result |> getByTestId(~matcher=#Str("go-to-settings")) |> FireEvent.click |> ignore)

      result |> getByTestId(~matcher=#Str("back-to-app")) |> expect |> toBeEnabled |> ignore

      act(() =>
        result
        |> getByTestId(~matcher=#Str("work-time-input"))
        |> FireEvent.change(
          ~eventInit={
            "target": {
              "value": "0",
            },
          },
        )
        |> ignore
      )

      result
      |> getByTestId(~matcher=#Str("back-to-app"))
      |> expect
      |> not__
      |> toBeEnabled
      |> ignore

      act(() =>
        result
        |> getByTestId(~matcher=#Str("work-time-input"))
        |> FireEvent.change(
          ~eventInit={
            "target": {
              "value": "20",
            },
          },
        )
        |> ignore
      )

      result |> getByTestId(~matcher=#Str("back-to-app")) |> expect |> toBeEnabled |> ignore

      result |> container |> Expect.expect |> Expect.toMatchSnapshot
    })

    test("should update focus time and break time after change the values on settings", () => {
      Jest.useFakeTimers()

      let result = <App /> |> render

      act(() => result |> getByTestId(~matcher=#Str("go-to-settings")) |> FireEvent.click |> ignore)

      act(() =>
        result
        |> getByTestId(~matcher=#Str("work-time-input"))
        |> FireEvent.change(
          ~eventInit={
            "target": {
              "value": "3",
            },
          },
        )
        |> ignore
      )

      act(() =>
        result
        |> getByTestId(~matcher=#Str("play-time-input"))
        |> FireEvent.change(
          ~eventInit={
            "target": {
              "value": "2",
            },
          },
        )
        |> ignore
      )

      act(() => result |> getByTestId(~matcher=#Str("back-to-app")) |> FireEvent.click |> ignore)

      result
      |> getByTestId(~matcher=#Str("current-phase"))
      |> expect
      |> toHaveTextContent(#Str("Focus"))
      |> ignore

      result
      |> getByTestId(~matcher=#Str("timer"))
      |> expect
      |> toHaveTextContent(#Str("03:00"))
      |> ignore

      act(() => result |> getByTestId(~matcher=#Str("jump")) |> FireEvent.click |> ignore)

      result
      |> getByTestId(~matcher=#Str("current-phase"))
      |> expect
      |> toHaveTextContent(#Str("Break"))
      |> ignore

      result
      |> getByTestId(~matcher=#Str("timer"))
      |> expect
      |> toHaveTextContent(#Str("02:00"))
      |> ignore

      result |> container |> Expect.expect |> Expect.toMatchSnapshot
    })
  })
})
