let appendZero = time => int_of_string(time) < 10 ? "0" ++ time : time;

let formatSeconds = time => {
  let minutes = string_of_int(time / 60) |> appendZero;
  let seconds = string_of_int(time mod 60) |> appendZero;

  minutes ++ ":" ++ seconds;
};

[@react.component]
let make = (~seconds) => {
  <Spread props={"data-testid": "timer"}>
    <h2 className="uk-text-center uk-heading-large">
      {React.string(formatSeconds(seconds))}
    </h2>
  </Spread>;
};
