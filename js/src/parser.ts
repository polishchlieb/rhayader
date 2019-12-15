import { PrimitiveExpression, Expression, Type } from './lexer';

function parsePrimitive(expression: PrimitiveExpression): any {
    if (expression.type == Type.number)
        return expression.value;
}

function parse(expression: Expression): any {
    if (expression.type == Type.number)
        return parsePrimitive(expression);
    if (expression.type == Type.operator) {
        return expression.children.reduce((acc, curr) => {
            let getValue = Function('a, b', `return a ${expression.value} b`);
            return getValue(acc, parse(curr));
        }, 0);
    }
}

export function parseExpression(expression: Expression): void {
    let current: any;
    let methods: { [k: string]: Function } = {
        print(value) {
            console.log(value);
        }
    };

    if (expression.type == Type.operator) {
        let sum = expression.children.reduce((acc, curr) => {
            let getValue = Function('a, b', `return a ${expression.value} b`);
            return getValue(acc, parse(curr));
        }, 0);
        console.log(sum);
    }

    if (expression.type == Type.functionCall) {
        const args: Array<any> = expression.data.arguments.map((argument: any) => {
            return parse(argument);
        });
        methods[expression.data.name](...args);
    }
}