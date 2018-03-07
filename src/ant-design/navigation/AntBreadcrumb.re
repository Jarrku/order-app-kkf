module Breadcrumb = {
  [@bs.module "antd/lib/breadcrumb"]
  external component : ReasonReact.reactClass = "default";
  let make = children =>
    ReasonReact.wrapJsForReason(~reactClass=component, children);
};