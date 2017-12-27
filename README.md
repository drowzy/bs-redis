# bs-redis

Bucklescript bindings for [node_redis](https://github.com/NodeRedis/node_redis)

**Status**: Experimental, lacking features

## Example
### Set / Get
```reason
let redis = Redis.createClient ();

let handler = (_err, msg) => {
  Js.log(msg);
};

Redis.set(redis, "key1", "value", handler) |> ignore;
Redis.hset(redis, "key2", "hash", [|"hello"|], handler) |> ignore;

Redis.get(redis, "key1", handler) |> ignore;
```

### Pubsub
```reason
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
```

## installation
```
npm i --save bs-redis
```

Add bs-redis to bs-dependencies in your bsconfig.json:

```
{
  ...
  "bs-dependencies": ["bs-redis"]
}
```
