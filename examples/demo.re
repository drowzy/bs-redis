let redis = Redis.createClient ();

let handler = (_err, msg) => {
  Js.log(msg);
};

Redis.set(redis, "key1", "value", handler) |> ignore;
Redis.hset(redis, "key2", "hash", [|"hello"|], handler) |> ignore;

Redis.get(redis, "key1", handler);
