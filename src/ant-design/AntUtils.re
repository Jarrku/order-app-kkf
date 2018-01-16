let fromOpt = Js.Nullable.from_opt;

type onClickEvent = ReasonReact.Callback.t(ReactEventRe.Mouse.t);

type jsUnsafe;

external toJsUnsafe : 'a => jsUnsafe = "%identity";

let toJs =
  fun
  | `String(s) => toJsUnsafe(s)
  | `Bool(b) => toJsUnsafe(Js.Boolean.to_js_boolean(b))
  | `Float(f) => toJsUnsafe(f)
  | `Date(d) => toJsUnsafe(d)
  | `Callback(c) => toJsUnsafe(c)
  | `Element(e) => toJsUnsafe(e)
  | `Object(o) => toJsUnsafe(o)
  | `Enum(_) => assert false;

let toBool = Js.Boolean.to_js_boolean;

let optionMap = (fn, option) =>
  switch option {
  | Some(value) => Some(fn(value))
  | None => None
  };

let unwrapOptionMap = (fn, option) => optionMap(fn, option) |> fromOpt;