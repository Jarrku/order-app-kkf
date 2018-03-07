open Utils;

open Ant;

requireCss("./home.css");

type state = int;

type action =
  | Increment
  | Decrement;

let component = ReasonReact.reducerComponent("Home");

let make = _children => {
  let handleNavigation = _event => ReasonReact.Router.push("kitchen");
  let handleChange = (event: Counter.counterOptions, self) =>
    switch event {
    | Counter.Increment => self.ReasonReact.send(Increment)
    | Counter.Decrement => self.ReasonReact.send(Decrement)
    };
  {
    ...component,
    initialState: () => 0,
    reducer: (action, state) =>
      switch action {
      | Increment => ReasonReact.Update(state + 1)
      | Decrement => ReasonReact.Update(state - 1)
      },
    render: self =>
      <div className="HomeContainer">
        <button className="item-d" onClick=handleNavigation>
          (textEl("Go to Kitchen"))
        </button>
        <Counter
          label="TestCounter"
          amount=self.state
          onChange=(self.handle(handleChange))
        />
        <div className="item-b"> (textEl("Element 2")) </div>
        <div className="item-c"> (textEl("Element 3")) </div>
      </div>
  };
};