module Icon {
  [@bs.module "antd/lib/icon"] external component : ReasonReact.reactClass = "default";
open AntUtils;
  let make = (~iconType: string, ~spin: option(bool)=?, ~style:option(ReactDOMRe.Style.t)=?, children) => {
    ReasonReact.wrapJsForReason(
      ~reactClass=component,
      ~props={
        "spin": unwrapOptionMap(toBool, spin),
        "style": fromOpt(style),
        "type": iconType
      },
      children
    );
  }
}