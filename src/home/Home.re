open Utils;

requireCss("./home.css");

let component = ReasonReact.statelessComponent("Home");

let make = _children => {
  ...component,
  render: _self =>
    <div className="HomeContainer">
      <button
        className="item-d" onClick=(_e => ReasonReact.Router.push("kitchen"))>
        (textEl("Go to Kitchen"))
      </button>
      <Card
        className="item-a"
        centered=true
        color=`red
        description=(textEl("description"))
      />
      <div className="item-b"> (textEl("Element 2")) </div>
      <div className="item-c"> (textEl("Element 3")) </div>
    </div>
};