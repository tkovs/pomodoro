open Jest;
open Expect;
open ReactTestingLibrary;

describe("Timer component", () => {
  test("should render", () => {
    <Toggle identifier="identifier" isReseted=false />
    |> render
    |> container
    |> expect
    |> toMatchSnapshot
  })
});
