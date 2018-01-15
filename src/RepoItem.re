let component = ReasonReact.statelessComponent("RepoItem");

let make = (~repo: RepoData.repo, _children) => {
  ...component,
  render: _self =>
    <Card
      href=repo.html_url
      centered=true
      description=(string_of_int(repo.stargazers_count) ++ " stars")
      header=repo.full_name
    />
};