import { Function } from "./Function";

export class Print implements Function {
    public name: string = "print";

    execute(args: string[], commandArgs: string[]): void {
        console.log(args.join(" "));
    }
}