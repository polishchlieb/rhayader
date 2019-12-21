import { executeFromLabel, findLabels, matchBrackets } from './Util';
import { openingBrackets, closingBrackets } from './globals';

const init = (): void => {
    findLabels();
    matchBrackets();
}

init();
executeFromLabel("main");