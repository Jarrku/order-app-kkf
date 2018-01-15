open Utils;

type routes = Home | Kitchen | Bar | Scan | Scanned(string);

type state = {
  nowShowing: routes
};

type action = {
  routing: routes
};

let component = ReasonReact.reducerComponent("Router");

let make = (_children) => {
  ...component,
initialState: () => { nowShowing: Scanned("test")},
reducer: (action: action, _state) => 
  switch action.routing {
  | Home => ReasonReact.Update({ nowShowing: Home})
  | Kitchen => ReasonReact.Update({ nowShowing: Kitchen});
  | Bar => ReasonReact.Update({ nowShowing: Bar});
  | Scan => ReasonReact.Update({ nowShowing: Scan});
  | Scanned(idVal) => ReasonReact.Update({ nowShowing: Scanned(idVal)});
  },
  render: (self) => {
    let componentToShow = switch self.state.nowShowing {
    | Home => <App />
    | Kitchen => <div>{textEl("Kitchen")}</div>
    | Bar => <div>{textEl("Bar")}</div>
    | Scan => <div>{textEl("Scan")}</div>
    | Scanned(id) => <div>{textEl("Scanned " ++ id)}</div>
    };

    <div id="routingContainer">
    componentToShow
    </div>
  }
}