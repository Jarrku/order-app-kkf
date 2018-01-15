[@bs.module "semantic-ui-react"]
external card : ReasonReact.reactClass = "Card";

open Utils;

let make =
    (
      ~header: option(string)=?,
      ~centered: option(bool)=?,
      ~description: option(string)=?,
      ~href: option(string)=?,
      ~extra: option(ReasonReact.reactElement)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=card,
    ~props={
      "header": fromOpt(header),
      "description": fromOpt(description),
      "centered": fromOptBool(centered),
      "href": fromOpt(href),
      "extra": fromOpt(extra)
    },
    children
  );