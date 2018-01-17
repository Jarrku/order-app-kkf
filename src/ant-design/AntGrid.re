module Grid = {
  [@bs.module "antd/lib/grid"]
  external component : ReasonReact.reactClass = "default";
  let make = children =>
    ReasonReact.wrapJsForReason(~reactClass=component, ~props={}, children);
};