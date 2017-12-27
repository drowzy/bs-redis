type error;
type callback('a) = ((Js.Null.t(error), 'a) => unit);

module Client = {
  type t;
};

module Subscriber = {
  type t = Client.t;
  [@bs.send.pipe : t] external subscribe: string => unit = "";

  [@bs.send.pipe : t] external on : ([@bs.string] 
  [ 
    | `subscribe((string, int) => unit) 
    | `psubsribe((string, int) => unit)
    | `unsubscribe((string, int) => unit)
    | `punsubscribe((string, int) => unit)
    | `message((string, string) => unit)
    | `pmessage((string, string, string) => unit)
    | `message_buffer((string, Buffer.t) => unit)
    | `pmessage_buffer((string, Buffer.t) => unit)
  ]) => t = "";
};

module Publisher = {
  type t = Client.t;
  [@bs.send.pipe : t] external publish: (string, string) => unit = "";
};

[@bs.module "redis"] external createClient : unit => Client.t = "";
[@bs.send] external quit : Client.t => unit => unit = "";
[@bs.send] external set : (Client.t, string, 'a, callback(string)) => unit = "";
[@bs.send] external get : (Client.t, string, callback(string)) => unit = "";
[@bs.send] external hset : (Client.t, string, string, 'a, callback(string)) => unit = "";
[@bs.send] external hkeys : (Client.t, string, callback(array(string))) => unit = "";
