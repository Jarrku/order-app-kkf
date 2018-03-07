module Steps = {
  [@bs.module "antd/lib/steps"]
  external component : ReasonReact.reactClass = "default";
  let make = children =>
    ReasonReact.wrapJsForReason(~reactClass=component, children);
};