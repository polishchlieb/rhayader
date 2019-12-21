import { Function } from "./Function";
import { variables } from "../globals";

export class Var implements Function {
    public name: string = "var";

    execute(args: string[], commandArgs: string[]): void {
        const data = args.join(" ").split("=");
        
        try {
            variables[data[0].trim()] = parseFloat(data[1].trim());
        } catch (e) {
            variables[data[0].trim()] = data[1].trim();
        }
    }
}