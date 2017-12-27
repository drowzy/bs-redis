type error;
type callback('a) = ((Js.Null.t(error), 'a) => unit);

module Client = {
  type t;
};

module Subscriber = {
  type t = Client.t;
  [@bs.send] external subscribe: (t, string) => unit = "";

  [@bs.send.pipe : t] external on : ([@bs.string] [ | `subscribe((string, int) => unit) | `message((string, string) => unit)]) => t = "";
};

[@bs.module "redis"] external createClient : unit => Client.t = "";
[@bs.send] external quit : Client.t => unit => unit = "";
[@bs.send] external set : (Client.t, string, 'a, callback(string)) => unit = "";
[@bs.send] external get : (Client.t, string, 'a, callback(string)) => unit = "";
[@bs.send] external hset : (Client.t, string, string, 'a, callback(string)) => unit = "";
[@bs.send] external hkeys : (Client.t, string, callback(array(string))) => unit = "";
