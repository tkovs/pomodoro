[@react.component]
let make = (~phase, ~value, ~onChange) =>
  <div className="uk-form-stacked">
    <label className="uk-form-label" htmlFor={phase ++ "-input"}>
      {React.string(phase ++ " time: ")}
    </label>
    <div className="uk-form-controls">
      <input
        value={string_of_int(value)}
        type_="number"
        onChange={e => e->ReactEvent.Form.target##value |> onChange}
        className="uk-input"
        id={phase ++ "-input"}
      />
    </div>
  </div>;
