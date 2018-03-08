[%bs.raw {|require('./app.css')|}];

[@bs.module] external logo : string = "./logo.svg";

let component = ReasonReact.statelessComponent("App");

let str = ReasonReact.stringToElement;

let blockStatusCases = List.map(
  state => (
    <div>
      <h3>{str(Block.Test.blockStateToString(state))}</h3>
      <BlockWithState initState=state>{str("Hello Block!")}</BlockWithState>
    </div>
  ),
  Block.Test.allBlockState()
);

let make = (_children) => {
  ...component,
  render: (_self) =>
    <div className="App">
      <h1>{str("LV-CORE-RE")}</h1>
      <h3>{str("Default Status")}</h3>
      <BlockWithState>{str("Hello Block!")}</BlockWithState>
      {blockStatusCases |> Array.of_list |> ReasonReact.arrayToElement}
    </div>
};
