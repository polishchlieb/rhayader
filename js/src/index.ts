import { parseExpression } from './parser';
import * as expression from './demo.json';
parseExpression(expression);

// import { Expression, Type } from './lexer';
// import { readFileSync } from 'fs';

// const expression: Expression = {
//     type: Type.operator,
//     value: '+',
//     children: [
//         {
//             type: Type.number,
//             value: 2
//         },
//         {
//             type: Type.number,
//             value: 2
//         },
//         {
//             type: Type.number,
//             value: 3
//         }
//     ]
// };