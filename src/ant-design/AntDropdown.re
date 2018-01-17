module Dropdown = {
  [@bs.module "antd/lib/dropdown"]
  external component : ReasonReact.reactClass = "default";
  let make = children =>
    ReasonReact.wrapJsForReason(~reactClass=component, ~props={}, children);
};