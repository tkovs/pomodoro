let requestPermission = [%raw
  {|
  function() {
    if (typeof Notification !== 'undefined') {
      return Notification.requestPermission()
    }
  }
  |}
];

let notify = [%raw
  {|
  function spawnNotification(title, body) {
    var options = {
      body,
      icon: "/favicon.ico",
    };
    if (typeof Notification !== 'undefined') {
      new Notification(title, options);
    }
  }
  |}
];
