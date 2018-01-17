module Layout = {
  [@bs.module "antd/lib/layout"]
  external component : ReasonReact.reactClass = "default";
  let make = children =>
    ReasonReact.wrapJsForReason(~reactClass=component, ~props={}, children);
};