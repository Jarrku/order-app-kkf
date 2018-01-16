[@bs.val] external requireCss : string => unit = "require";

[@bs.val] external requireAssetURI : string => string = "require";

[@bs.module]
external registerServiceWorker : unit => unit = "src/registerServiceWorker";

type re = ReasonReact.reactElement;

let textEl = ReasonReact.stringToElement;

let arrayEl = ReasonReact.arrayToElement;

let mapToReact = (fn, elements) => Array.map(fn, elements) |> arrayEl;

let intEl = n => n |> string_of_int |> ReasonReact.stringToElement;

let fromOpt = Js.Nullable.from_opt;

let fromOptBool = (toConvert: option(bool)) =>
  switch toConvert {
  | None => Js.false_
  | Some(toConvert) => Js.Boolean.to_js_boolean(toConvert)
  };

let null = Js.Nullable.null;

let nullabe = Js.Nullable.return;

type jsUnsafe;

external toJsUnsafe : 'a => jsUnsafe = "%identity";

let unwrapValue =
  fun
  | `String(s) => toJsUnsafe(s)
  | `Bool(b) => toJsUnsafe(Js.Boolean.to_js_boolean(b))
  | `Float(f) => toJsUnsafe(f)
  | `Date(d) => toJsUnsafe(d)
  | `Callback(c) => toJsUnsafe(c)
  | `Element(e) => toJsUnsafe(e)
  | `Object(o) => toJsUnsafe(o)
  | `Enum(_) => assert false;

let optionMap = (fn, option) =>
  switch option {
  | Some(value) => Some(fn(value))
  | None => None
  };

let unwrapOptionMap = (fn, option) => optionMap(fn, option) |> fromOpt;