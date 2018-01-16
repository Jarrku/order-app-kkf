open Utils;

type routes =
  | Home
  | Kitchen
  | Bar
  | Scan
  | Scanned(string);

type state = {nowShowing: routes};

type action =
  | ShowHome
  | ShowKitchen
  | ShowBar
  | ShowScan
  | ShowScanned(string);

let component = ReasonReact.reducerComponent("Router");

let make = _children => {
  ...component,
  initialState: () => {nowShowing: Home},
  didMount: _a => {
    ReasonReact.Router.push("/");
    ReasonReact.NoUpdate;
  },
  reducer: (action: action, _state) =>
    switch action {
    | ShowHome => ReasonReact.Update({nowShowing: Home})
    | ShowKitchen => ReasonReact.Update({nowShowing: Kitchen})
    | ShowBar => ReasonReact.Update({nowShowing: Bar})
    | ShowScan => ReasonReact.Update({nowShowing: Scan})
    | ShowScanned(idVal) => ReasonReact.Update({nowShowing: Scanned(idVal)})
    },
  subscriptions: self => [
    Sub(
      () =>
        ReasonReact.Router.watchUrl(url =>
          switch url.path {
          | [] => self.send(ShowHome)
          | ["home"] => self.send(ShowHome)
          | ["kitchen"] => self.send(ShowKitchen)
          | ["bar"] => self.send(ShowBar)
          | ["scan"] => self.send(ShowScan)
          | ["scan", id] => self.send(ShowScanned(id))
          | _ => self.send(ShowHome)
          }
        ),
      ReasonReact.Router.unwatchUrl
    )
  ],
  render: self =>
    switch self.state.nowShowing {
    | Home => <Home />
    | Kitchen => <App />
    | Bar => <div> (textEl("Bar")) </div>
    | Scan => <div> (textEl("Scan")) </div>
    | Scanned(id) => <div> (textEl("Scanned " ++ id)) </div>
    }
};