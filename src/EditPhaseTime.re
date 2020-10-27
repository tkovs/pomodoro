[@react.component]
let make = (~phase, ~value, ~onChange) =>
  <div>
    <label> {React.string(phase ++ " time: ")} </label>
    <input
      value={string_of_int(value)}
      type_="number"
      onChange={e => e->ReactEvent.Form.target##value |> onChange}
    />
  </div>;
