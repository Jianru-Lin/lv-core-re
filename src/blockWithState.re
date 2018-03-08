type action =
    | Change(Block.block_state);

let component = ReasonReact.reducerComponent("BlockWithState");

let make = (~initState = Block.newBlockState(), children) => {
    ...component,
    initialState: () => initState,
    reducer: (action, _state) =>
        switch (action) {
        | Change(newState) => ReasonReact.Update(newState)
        },
    render: self =>
        <Block
            state=self.state
            onChange={newState => self.send(Change(newState))}>
            ...children
        </Block>
}