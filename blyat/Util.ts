import { executeLines } from './Executor';
import { lines, openingBrackets, closingBrackets, functions, setClosingBrackets } from './globals';
import { CustomFunction } from './CustomFunction';

const testCondition = (condition: string[]): boolean => {
    if (condition[1] === "==") {
        if (condition[0].toString() === condition[2].toString()) {
            return true;
        }
    }

    if (condition[1] === ">") {
        if (condition[0] > condition[2]) {
            return true;
        }
    }

    if (condition[1] === "<") {
        if (condition[0] < condition[2]) {
            return  true;
        }
    }

    if (condition[1] === "!=") {
        if (condition[0] != condition[2]) {
            return  true;
        }
    }

    return false;
}

const matchBrackets = (): void => {
    let temp: number[] = [];
    let a: number = 0;
    let b: number = 0;

    for (let i = 0; i < lines.length; i++) {
        const line = lines[i].trim();

        if (line.startsWith("//")) continue;

        if (line.includes("{")) {
            a++;
            openingBrackets.push(i);
        }

        if (line.includes("}")) {
            b++;
            temp.unshift(i);
        }

        if ((a == b) && (a != 0)) {
            setClosingBrackets(closingBrackets.concat(temp));
            temp = [];
        }
    }
}

const getMatchingBracket = (line: number): number => {
    return closingBrackets[openingBrackets.indexOf(line)];
}

const findLabels = (): void => {
    for (let i = 0; i < lines.length; i++) {
        const line: string = lines[i].trim();

        if (line.startsWith("//")) continue;

        const arr: string[] = line.split(" ");

        if (arr[0] === "def" && line.endsWith("{")) {
            const args: string[] = [];

            for (const arg of arr.slice(2)) {
                if (arg === "{") break;

                args.push(arg);
            }

            functions.push(new CustomFunction(arr[1], i, args));
        }
    }
}

const executeFromLabel = (labelName) => {
    const fun: CustomFunction = functions.find((cf: CustomFunction) => cf.name === labelName);
    executeLines(fun.index, getMatchingBracket(fun.index));
}

export {
    getMatchingBracket,
    executeFromLabel,
    findLabels,
    testCondition,
    matchBrackets
}