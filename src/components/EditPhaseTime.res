@react.component
let make = (~phase, ~value, ~onChange, ~testId) =>
  <div className="uk-form-stacked uk-margin-small">
    <label className="uk-form-label" htmlFor={phase ++ "-input"}>
      {React.string(phase ++ " time: ")}
    </label>
    <div className="uk-form-controls">
      <Spread props={"data-testid": testId}>
        <input
          value={string_of_int(value / 60)}
          type_="number"
          min="0"
          onChange={e => {
            let newValue = (e->ReactEvent.Form.target)["value"]

            if newValue > 0 && newValue < 9999 {
              newValue * 60 |> onChange
            }
          }}
          className="uk-input uk-border-pill"
          id={phase ++ "-input"}
          required=true
        />
      </Spread>
    </div>
  </div>
