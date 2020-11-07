[@react.component]
let make = (~session, ~maxSessions) =>
  <Spread props={"data-testid": "session"}>
    <div className="uk-text-meta">
      {let session = string_of_int(session);
       let sessions = string_of_int(maxSessions);
       React.string(session ++ "/" ++ sessions)}
    </div>
  </Spread>;
