[@react.component]
let make = (~phase: State.phase) =>
  <Spread props={"data-testid": "current-phase"}>
    <span>
      {switch (phase) {
       | State.Work => React.string("Focus")
       | State.Play => React.string("Break")
       }}
    </span>
  </Spread>;
