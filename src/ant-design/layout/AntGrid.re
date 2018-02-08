open AntUtils;

module Row = {
  [@bs.module "antd/lib/row"]
  external component : ReasonReact.reactClass = "default";
  module Align = {
    type t =
      | Top
      | Middle
      | Bottom;
    let toString =
      fun
      | Top => "top"
      | Middle => "middle"
      | Bottom => "bottom";
  };
  module Justify = {
    type t =
      | Start
      | End
      | Center
      | SpaceAround
      | SpaceBetween;
    let toString =
      fun
      | Start => "start"
      | End => "end"
      | Center => "center"
      | SpaceAround => "space-around"
      | SpaceBetween => "space-between";
  };
  module LayoutType = {
    type t =
      | Flex;
    let toString =
      fun
      | Flex => "flex";
  };
  let make =
      (
        ~align: option(Align.t),
        ~gutter: option([ | `Bool(bool) | `Object({. "delay": int})])=?,
        ~justify: option(Justify.t)=?,
        ~layoutType: option(LayoutType.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=component,
      ~props={
        "align": unwrapOptionMap(Align.toString, align),
        "gutter": unwrapOptionMap(toJs, gutter),
        "justify": unwrapOptionMap(Justify.toString, justify),
        "layout": unwrapOptionMap(LayoutType.toString, layoutType)
      },
      children
    );
};

module Col = {
  [@bs.module "antd/lib/col"]
  external component : ReasonReact.reactClass = "default";
  let make = children =>
    ReasonReact.wrapJsForReason(~reactClass=component, children);
};