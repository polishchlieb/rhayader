import { executeLines } from './Executor';
import { getMatchingBracket } from './Util';
import { setTempVariable, removeTempVariable } from './Variables';

export class CustomFunction {
    constructor(public name: string, public index: number, public args?: string[]) {}

    public execute(args?: string[]): void {
        for (let i = 0; i < this.args.length; i++) {
            setTempVariable(this.args[i], args[i]);
        }

        executeLines(this.index, getMatchingBracket(this.index));

        for (let i = 0; i < this.args.length; i++) {
            removeTempVariable(this.args[i]);
        } 
    }
}