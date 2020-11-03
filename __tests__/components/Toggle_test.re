open Jest;
open Expect;
open ReactTestingLibrary;

describe("Timer component", () => {
  test("should render", () => {
    <Toggle identifier="identifier" />
    |> render
    |> container
    |> expect
    |> toMatchSnapshot
  })
});
