module Button = {
  [@bs.module "antd/lib/button"]
  external button : ReasonReact.reactClass = "default";
  open AntUtils;
  module Icon = {
    type t =
      | StepBackwards
      | Down;
    let toString =
      fun
      | StepBackwards => "button"
      | Down => "down";
  };
  module Shape = {
    type t =
      | Circle;
    let toString =
      fun
      | Circle => "circle";
  };
  module Size = {
    type t =
      | Small
      | Large;
    let toString =
      fun
      | Small => "small"
      | Large => "large";
  };
  module OfType = {
    type t =
      | Primary
      | Ghost
      | Dashed
      | Danger;
    let toString =
      fun
      | Primary => "primary"
      | Ghost => "ghost"
      | Dashed => "dashed"
      | Danger => "danger";
  };
  let make =
      (
        ~ghost: bool=false,
        ~href: option(string)=?,
        ~htmlType: string="button",
        ~loading: option([ | `Bool(bool) | `Object({. "delay": int})])=?,
        ~icon: option(Icon.t)=?,
        ~shape: option(Shape.t)=?,
        ~size: option(Size.t)=?,
        ~target: option(string)=?,
        ~ofType: option(OfType.t)=?,
        ~onClick: option(onClickEvent)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=button,
      ~props={
        "ghost": ghost,
        "href": fromOpt(href),
        "htmlType": htmlType,
        "loading": unwrapOptionMap(toJs, loading),
        "icon": unwrapOptionMap(Icon.toString, icon),
        "shape": unwrapOptionMap(Shape.toString, shape),
        "size": unwrapOptionMap(Size.toString, size),
        "target": fromOpt(target),
        "type": unwrapOptionMap(OfType.toString, ofType),
        "onClick": fromOpt(onClick)
      },
      children
    );
  module Group = {
    [@bs.module "antd/lib/button/button-group"]
    external buttonGroup : ReasonReact.reactClass = "default";
    let make = (~size: option(Size.t)=?, children) =>
      ReasonReact.wrapJsForReason(
        ~reactClass=buttonGroup,
        ~props={"size": unwrapOptionMap(Size.toString, size)},
        children
      );
  };
};