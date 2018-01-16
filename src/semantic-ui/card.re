[@bs.module "semantic-ui-react"]
external card : ReasonReact.reactClass = "Card";

open Utils;

[@bs.deriving jsConverter]
type colors = [
  | `red
  | `orange
  | `yellow
  | `olive
  | `green
  | `teal
  | `blue
  | `violet
  | `purple
  | `pink
  | `brown
  | `grey
  | `black
];

let getColorVal = (color: option(colors)) =>
  switch color {
  | None => `black
  | Some(color) => color
  };

let make =
    (
      ~asElement: option(string)=?,
      ~centered: option(bool)=?,
      ~className: option(string)=?,
      ~color: option(colors)=?,
      ~content: option(re)=?,
      ~description: option(re)=?,
      ~extra: option(re)=?,
      ~fluid: option(bool)=?,
      ~meta: option(re)=?,
      ~header: option(re)=?,
      ~href: option(string)=?,
      ~image: option(re)=?,
      ~link: option(bool)=?,
      ~onClick: option(string => unit)=?,
      ~raised: option(bool)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=card,
    ~props={
      "as": fromOpt(asElement),
      "color": color |> getColorVal |> colorsToJs,
      "content": fromOpt(content),
      "fluid": fromOptBool(fluid),
      "meta": fromOpt(meta),
      "image": fromOpt(image),
      "link": fromOpt(link),
      "onClick": fromOpt(onClick),
      "raised": fromOptBool(raised),
      "header": fromOpt(header),
      "className": fromOpt(className),
      "description": fromOpt(description),
      "centered": fromOptBool(centered),
      "href": fromOpt(href),
      "extra": fromOpt(extra)
    },
    children
  );