open Jest;
open Expect;
open ReactTestingLibrary;

describe("Timer component", () => {
  test("with less than 60 seconds", () => {
    <Timer seconds=15 /> |> render |> container |> expect |> toMatchSnapshot
  });

  test("with more than 60 seconds", () => {
    <Timer seconds=1500 /> |> render |> container |> expect |> toMatchSnapshot
  });
});
