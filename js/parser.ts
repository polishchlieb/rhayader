enum Type {
    operator,
    string,
    number
}

interface PrimitiveExpression {
    type: Type;
    value: any;
}

interface Expression extends PrimitiveExpression {
    children?: PrimitiveExpression[];
    data?: Object;
}

function parsePrimitive(expression: PrimitiveExpression): any {
    if (expression.type == Type.number)
        return expression.value;
}

function parseExpression(expression: Expression): void {
    let current = [];

    if (expression.value == '+') {
        current = expression.children.reduce((acc, curr) => {
            return acc + parsePrimitive(curr);
        }, 0);
    }

    console.log(current);
}

const expression: Expression = {
    type: Type.operator,
    value: '+',
    children: [
        {
            type: Type.number,
            value: 2
        },
        {
            type: Type.number,
            value: 2
        }
    ]
};

parseExpression(expression);