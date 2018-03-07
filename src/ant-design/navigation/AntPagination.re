module Pagination = {
  [@bs.module "antd/lib/pagination"]
  external component : ReasonReact.reactClass = "default";
  let make = children =>
    ReasonReact.wrapJsForReason(~reactClass=component, children);
};