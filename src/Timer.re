let appendZero = time => int_of_string(time) < 10 ? "0" ++ time : time;

let formatSeconds = time => {
  let minutes = string_of_int(time / 60) |> appendZero;
  let seconds = string_of_int(time mod 60) |> appendZero;

  minutes ++ ":" ++ seconds;
};

[@react.component]
let make = (~seconds) => {
  <div className="uk-text-center uk-text-large uk-text-bold">
    {React.string(formatSeconds(seconds))}
  </div>;
};
