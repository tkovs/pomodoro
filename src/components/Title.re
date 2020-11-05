open ReasonUIKit;

[@react.component]
let make = () =>
  <Container size=Container.SizeSmall>
    <h3 className="uk-text-center"> {React.string("Pomodoro")} </h3>
  </Container>;
