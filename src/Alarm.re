[@bs.module "./sounds/alarm.mp3"] external sound: string = "default";

let requestPermission = () =>
  try(Notification.requestPermission()) {
  | _ => Js.log("Notifications not supported.")
  };

let alarm = (~title, ~message) => {
  let content: Notification.content = {
    "body": message,
    "icon": "./favicon.ico",
  };

  let notify = () => {
    Notification.make(title, content)->ignore;
    let audio = Audio.make(sound);
    Audio.play(audio);
  };

  try(notify()) {
  | _ => Js.log("Error sending notification.")
  };
};
