import { PrimitiveExpression, Expression, Type } from './lexer';

function parsePrimitive(expression: PrimitiveExpression): any {
    if (expression.type == Type.number)
        return expression.value;
}

function parse(expression: Expression): any {
    if (expression.type == Type.number)
        return parsePrimitive(expression);
}

export function parseExpression(expression: Expression): void {
    let current: any;

    if (expression.value == '+') {
        current = expression.children.reduce((acc, curr) => {
            return acc + parse(curr);
        }, 0);
    }

    console.log(current);
}