@react.component
let make = (~workTime, ~playTime, ~setWorkTime, ~setPlayTime) => <>
  <div className="uk-text-center uk-margin"> {React.string("Settings")} </div>
  <EditPhaseTime
    phase="Work" value=workTime onChange={e => setWorkTime(e)} testId="work-time-input"
  />
  <EditPhaseTime
    phase="Play" value=playTime onChange={e => setPlayTime(e)} testId="play-time-input"
  />
</>
