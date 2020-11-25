type notification

type content = {"body": string, "icon": string}

@bs.new external make: (string, content) => notification = "Notification"
@bs.val @bs.scope("Notification")
external requestPermission: unit => unit = "requestPermission"
