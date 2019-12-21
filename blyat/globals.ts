import { readFileSync } from "fs";
import { CustomFunction } from './CustomFunction';

// export default {
//     labels: {},
//     openingBrackets: [],
//     closingBrackets: [],
//     variables: {},
//     lines: []
// }

const lines: string[] = readFileSync('./test.asn').toString('utf-8').split("\n");
const functions: CustomFunction[] = [];
const openingBrackets: number[] = [];
let closingBrackets: number[] = [];
const variables: {} = {};
const tempVariables: {} = {};

const setClosingBrackets = (arr: number[]): void => {
    closingBrackets = arr;
}

export {
    lines,
    functions,
    openingBrackets,
    closingBrackets,
    variables,
    setClosingBrackets,
    tempVariables
};