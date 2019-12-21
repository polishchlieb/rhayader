import { Node } from './evaluator';

export function parse(expr: string): Node {
    return <Node>{};
}

export function parseLine(line: string): Node {
    if (/(?<=[A-Z,a-z]+\().+(?=\))/)
}