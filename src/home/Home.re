open Utils;

requireCss("./home.css");

let handleChange = (what: Counter.counterOptions) =>
  switch what {
  | Counter.Increment => Js.log("Incrementing...")
  | Counter.Decrement => Js.log("Decrementing...")
  };

let component = ReasonReact.statelessComponent("Home");

open Ant;

let make = _children => {
  ...component,
  render: _self =>
    <div className="HomeContainer">
      <button
        className="item-d" onClick=(_e => ReasonReact.Router.push("kitchen"))>
        (textEl("Go to Kitchen"))
      </button>
      <Button.Group>
        <Button
          loading=(`Object({"delay": 10})) ofType=Ant.Button.OfType.Primary>
          (textEl("Ant Button"))
        </Button>
        <Button
          loading=(`Object({"delay": 10})) ofType=Ant.Button.OfType.Primary>
          (textEl("Ant Button"))
        </Button>
      </Button.Group>
      <Counter label="TestCounter" amount=0 onChange=handleChange />
      <div className="item-b"> (textEl("Element 2")) </div>
      <div className="item-c"> (textEl("Element 3")) </div>
    </div>
};