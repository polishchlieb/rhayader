import { Function } from "./Function";
import { variables } from "../globals";

export class Add implements Function {
    public name: string = "add";

    execute(args: string[], commandArgs: string[]): void {
        variables[commandArgs[0]] += parseFloat(commandArgs[1]);
    }
}