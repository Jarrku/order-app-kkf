module Menu = {
  [@bs.module "antd/lib/menu"]
  external component : ReasonReact.reactClass = "default";
  let make = children =>
    ReasonReact.wrapJsForReason(~reactClass=component, ~props={}, children);
};