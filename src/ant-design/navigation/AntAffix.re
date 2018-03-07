module Affix = {
  [@bs.module "antd/lib/affix"]
  external component : ReasonReact.reactClass = "default";
  let make = children =>
    ReasonReact.wrapJsForReason(~reactClass=component, children);
};