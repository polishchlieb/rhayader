import { evaluateParentNode, display, Node, Type } from './evaluator';

const expression: Node = {
    type: Type.functionCall,
    value: false,
    data: {
        name: "print",
        arguments: [
            {
                type: Type.operator,
                value: "+",
                children: [
                    {
                        type: Type.operator,
                        value: "*",
                        children: [
                            { type: Type.number, value: 3 },
                            { type: Type.number, value: 2 }
                        ]
                    },
                    { type: Type.number, value: 3 }
                ]
            }
        ]
    }
};

display(expression);
evaluateParentNode(expression);