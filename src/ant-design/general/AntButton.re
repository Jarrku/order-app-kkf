module Button = {
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
  [@bs.module "antd/lib/button"]
  external component : ReasonReact.reactClass = "default";
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
      ~reactClass=component,
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
    external groupComponent : ReasonReact.reactClass = "default";
    let make = (~size: option(Size.t)=?, children) =>
      ReasonReact.wrapJsForReason(
        ~reactClass=groupComponent,
        ~props={"size": unwrapOptionMap(Size.toString, size)},
        children
      );
  };
};