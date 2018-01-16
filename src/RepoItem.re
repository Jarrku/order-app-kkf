let component = ReasonReact.statelessComponent("RepoItem");

open Utils;

let make = (~repo: RepoData.repo, _children) => {
  ...component,
  render: _self =>
    <div>
      <h3> (textEl(repo.full_name)) </h3>
      <a href=repo.html_url>
        (textEl(string_of_int(repo.stargazers_count) ++ " stars"))
      </a>
    </div>
};