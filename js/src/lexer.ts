// TODO: https://areknawo.com/the-lexer-in-js/

export enum Type {
    operator,
    string,
    number
}

export interface PrimitiveExpression {
    type: Type;
    value: any;
}

export interface Expression extends PrimitiveExpression {
    children?: PrimitiveExpression[];
    data?: Object;
}

export function lex(): Expression {
    return <Expression>{};
}