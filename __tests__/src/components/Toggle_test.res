open Jest
open Expect
open ReactTestingLibrary

describe("Timer component", () =>
  test("should render", () =>
    <Toggle identifier="identifier" isReseted=false nonValidTime=false onBackToApp={_ => ()} />
    |> render
    |> container
    |> expect
    |> toMatchSnapshot
  )
)
