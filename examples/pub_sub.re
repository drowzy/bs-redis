let publisher = Redis.createClient ();
let subscriber = Redis.createClient ();
let channel = "mychannel";

let msgHandler = (channel, message) => {
  Js.log("Received message on: " ++ channel ++ " with message: " ++ message);
};

subscriber
  |> Redis.Subscriber.on(`message(msgHandler))
  |> Redis.Subscriber.on(`subscribe((ch, _count) => Redis.Publisher.publish(ch, "message", publisher)))
  |> Redis.Subscriber.subscribe(channel)
  |> ignore;
