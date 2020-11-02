open Jest;
open Expect;
open ReactTestingLibrary;

describe("Footer component", () => {
  test("pure", () => {
    <Footer /> |> render |> container |> expect |> toMatchSnapshot
  })
});
