[%bs.raw {|require('./block.css')|}];

let component = ReasonReact.statelessComponent("Block");

type block_state = {
    isOpen: bool,
    isHover: bool,
};

let newBlockState = () => {
    isOpen: false,
    isHover: false,
};

let make = (~state = newBlockState(), ~onChange, children) => {
    ...component,
    render: _self =>
        <div
            className=(
                "Block"
                ++ " " ++ (if (state.isOpen) "open" else "close")
                ++ " " ++ (if (state.isHover) "hover" else "")
            )
            onClick={_e => onChange({...state, isOpen: !state.isOpen})}>
            {
                if (state.isOpen) {
                    ReasonReact.arrayToElement(children)
                }
                else {
                    ReasonReact.stringToElement("...")
                }
            }
        </div>
};

module Test = {
    let allBlockState = () => [
        {isOpen: false, isHover: false},
        {isOpen: true, isHover: false},
        {isOpen: false, isHover: true},
        {isOpen: true, isHover: true},
    ];

    let blockStateToString = (state) => "{ isOpen:" ++ Lv.Utils.boolToString(state.isOpen) ++ ", isHover: " ++ Lv.Utils.boolToString(state.isHover) ++ "}";
};
