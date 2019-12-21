import { times } from './util';

export enum Type {
    operator,
    string,
    number,
    functionCall,
    assignment
}

export interface PrimitiveNode {
    type: Type;
    value: any;
}

export interface Node extends PrimitiveNode {
    children?: Node[];
    data?: any;
}

let methods: { [k: string]: Function } = {
    print(value: any) {
        console.log(value);
    }
};

export function evaluatePrimitiveNode(node: Node): any {
    if (node.type == Type.number)
        return node.value;
}


export function evaluateNode(node: Node): any {
    if (node.type == Type.number || node.type == Type.string)
        return evaluatePrimitiveNode(node);

    if (node.type == Type.operator) {
        if (node.value == '+')
            return evaluateNode(node.children[0]) + evaluateNode(node.children[1]);
        else if (node.value == '-')
            return evaluateNode(node.children[0]) - evaluateNode(node.children[1]);
        else if (node.value == '*')
            return evaluateNode(node.children[0]) * evaluateNode(node.children[1]);
        else if (node.value == '/')
            return evaluateNode(node.children[0]) / evaluateNode(node.children[1]);
    }

    if (node.type == Type.functionCall) {
        const args: Array<any> = node.data.arguments.map((argument: any) => {
            return evaluateNode(argument);
        });
        const result = methods[node.data.name](...args);
        if (result) console.log(result);
    }
}

export function evaluateParentNode(node: Node): void {
    if (node.type == Type.number || node.type == Type.string) {
        return evaluatePrimitiveNode(node);
    }

    if (node.type == Type.operator) {
        if (node.value == '+')
            console.log(evaluateNode(node.children[0]) + evaluateNode(node.children[1]));
        else if (node.value == '-')
            console.log(evaluateNode(node.children[0]) - evaluateNode(node.children[1]));
        else if (node.value == '*')
            console.log(evaluateNode(node.children[0]) * evaluateNode(node.children[1]));
        else if (node.value == '/')
            console.log(evaluateNode(node.children[0]) / evaluateNode(node.children[1]));
    }

    if (node.type == Type.functionCall) {
        const args: Array<any> = node.data.arguments.map((argument: any) => {
            return evaluateNode(argument);
        });
        const result = methods[node.data.name](...args);
        if (result) console.log(result);
    }
}

export function display(node: Node, branch = 0) {
    process.stdout.write(String(times('  ', branch)) + '- ');
    process.stdout.write(String(node.value || node.data.name) + '\n');

    if (node.children)
        node.children.forEach(child => display(child, branch + 1));
    if (node.data && node.data.arguments)
        node.data.arguments.forEach((child: Node) =>
            display(child, branch + 1));
}