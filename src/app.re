[%%bs.raw {|
  require('./index.css');
|}];

type state = {repoData: option(array(RepoData.repo))};

let dummyRepo: array(RepoData.repo) = [|
  RepoData.parseRepoJson(
    Js.Json.parseExn(
      {js|
        {"stargazers_count": 26, "full_name": "Simon", "html_url": "https://github.com/"}
      |js}
    )
  )
|];

type action =
  | Loaded(array(RepoData.repo));

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  initialState: () => {repoData: None},
  reducer: (action, _state) =>
    switch action {
    | Loaded(loadedRepo) => ReasonReact.Update({repoData: Some(loadedRepo)})
    },
  didMount: self => {
    Js.Promise.(
      RepoData.fetchRepos()
      |> then_(repoData => {
           self.send(Loaded(repoData));
           resolve();
         })
      |> ignore
    );
    ReasonReact.NoUpdate;
  },
  render: self => {
    let loadedReposButton =
      <button onClick=(_event => self.send(Loaded(dummyRepo)))>
        (ReasonReact.stringToElement("Load Repos"))
      </button>;
    let repoItems =
      switch self.state.repoData {
      | Some(repos) =>
        ReasonReact.arrayToElement(
          Array.map(
            (repo: RepoData.repo) => <RepoItem key=repo.full_name repo />,
            repos
          )
        )
      | None => ReasonReact.stringToElement("Loading")
      };
    <div className="App">
      <h1> (ReasonReact.stringToElement("Reason Projects")) </h1>
      loadedReposButton
      repoItems
    </div>;
  }
};