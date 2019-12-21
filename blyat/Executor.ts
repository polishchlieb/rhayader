import { Print } from "./functions/Print";
import { Var } from "./functions/Var";
import { Function } from "./functions/Function";
import { testCondition, getMatchingBracket } from "./Util";
import { lines, variables, openingBrackets, closingBrackets, functions, tempVariables } from "./globals";
import { setTempVariable, removeTempVariable } from "./Variables";
import { Add } from './functions/Add';

const builtInFunctions: Function[] = [
    new Print(),
    new Var(),
    new Add()
];

export function executeLines(start: number, end: number): void {
    for (let i = start; i < end; i++) {
        const line = lines[i].trim();
        const args: string[] = line.trim().split(" ");
        const command = args.shift().trim();
        const commandArgs = args.join(" ").split(",").map((s: string) => s.trim());

        if (line.startsWith("//")) continue;

        for (let i = 0; i < args.length; i++) {
            if (args[i].startsWith("%")) {
                const varName = args[i].replace("%", "").trim();

                args[i] = variables[varName];

                if (tempVariables[varName]) {
                    args[i] = tempVariables[varName];
                }
            } 
        }

        for (let i = 0; i < commandArgs.length; i++) {
            if (commandArgs[i].startsWith("%")) {
                const varName = commandArgs[i].replace("%", "").trim();

                commandArgs[i] = variables[varName];

                if (tempVariables[varName]) {
                    commandArgs[i] = tempVariables[varName];
                }
            } 
        }

        if (command === '}') {
            break;
        }

        if (command === 'if') {
            const matchingBracket: number = getMatchingBracket(i);

            if (testCondition(args)) {              
                executeLines(i + 1, matchingBracket);

                i = matchingBracket;
            } else {
                i = matchingBracket;
            }
        }

        if (command === 'for') {
            const varName = args[0];
            const range = args.slice(2).join("").split("{")[0].trim().split("..");
            
            const matchingBracket: number = getMatchingBracket(i);

            for (let i2 = parseInt(range[0]); i2 < parseInt(range[1]); i2++) {
                setTempVariable(varName, i2.toString());

                executeLines(i + 1, matchingBracket);
            }

            i = matchingBracket;

            removeTempVariable(varName);
        }

        for (const fun of functions) {
            if (fun.name === command) {
                fun.execute(commandArgs);
            }
        }

        for (const fun of builtInFunctions) {
            if (fun.name === command) {
                fun.execute(args, commandArgs);
            }
        }
    }
}
