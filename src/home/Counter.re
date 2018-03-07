open Utils;

type counterOptions =
  | Increment
  | Decrement;

let component = ReasonReact.statelessComponent("Counter");

let make =
    (
      ~amount: int,
      ~label: string,
      ~onChange: counterOptions => unit,
      _children
    ) => {
  ...component,
  render: _self =>
    <div>
      <h3> (textEl(label)) </h3>
      <button onClick=(_event => onChange(Increment))>
        (textEl("Increment"))
      </button>
      <button onClick=(_event => onChange(Decrement))>
        (textEl("Decrement"))
      </button>
      (textEl("Current amount: " ++ string_of_int(amount)))
    </div>
};