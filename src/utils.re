[@bs.val] external requireCss : string => unit = "require";

[@bs.val] external requireAssetURI : string => string = "require";

[@bs.module]
external registerServiceWorker : unit => unit = "src/registerServiceWorker";

type re = ReasonReact.reactElement;

let textEl = ReasonReact.stringToElement;

let arrayEl = ReasonReact.arrayToElement;

let intEl = n => n |> string_of_int |> ReasonReact.stringToElement;

let fromOpt = Js.Nullable.from_opt;

let fromOptBool = (toConvert: option(bool)) =>
  switch toConvert {
  | None => Js.false_
  | Some(toConvert) => Js.Boolean.to_js_boolean(toConvert)
  };