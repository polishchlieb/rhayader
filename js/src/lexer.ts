// TODO: https://areknawo.com/the-lexer-in-js/

export enum Type {
    operator,
    string,
    number,
    functionCall
}

export interface PrimitiveExpression {
    type: Type;
    value: any;
}

export interface Expression extends PrimitiveExpression {
    children?: PrimitiveExpression[];
    data?: any;
}

export function lex(): Expression {
    return <Expression>{};
}