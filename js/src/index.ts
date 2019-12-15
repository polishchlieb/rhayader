import { parseExpression } from './parser';
import { Expression } from './lexer';

const expression: Expression = {
    type: 3, // Type.functionCall
    value: false,
    data: {
        name: "print",
        arguments: [
            {
                type: 0, // Type.operator
                value: "+",
                children: [
                    {
                        type: 2, // Type.number
                        value: 2
                    },
                    {
                        type: 2, // Type.number
                        value: 3
                    }
                ]
            }
        ]
    }
};

parseExpression(expression);