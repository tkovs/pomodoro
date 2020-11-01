[@react.component]
let make = (~phase, ~value, ~onChange) =>
  <div className="uk-form-stacked uk-margin-small">
    <label className="uk-form-label" htmlFor={phase ++ "-input"}>
      {React.string(phase ++ " time: ")}
    </label>
    <div className="uk-form-controls">
      <input
        value={string_of_int(value)}
        type_="number"
        min="0"
        onChange={e => e->ReactEvent.Form.target##value |> onChange}
        className="uk-input uk-border-pill"
        id={phase ++ "-input"}
        required=true
      />
    </div>
  </div>;
