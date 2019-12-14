// TODO: https://areknawo.com/the-lexer-in-js/
// remove this comment

function parseExpression(line: string): void {
    let scope = 0;
    let nodes = [];
    let current = '';
    let previousType: Type = null;

    let i = -1;
    for (let char of line) {
        ++i;

        let currentType: Type = Util.getType(char);
        if (currentType == Type.white) continue;
        if (Util.getType(char) != previousType && i != 0) {
            nodes.push(current);
            current = '';
        }
        if (i == line.length && current.length > 0) {
            nodes.push(current);
        }

        current += char;
    }

    console.log(nodes);
}

enum Type {
    number,
    letter,
    operator,
    white
}

class Util {

    static getType(c: string): Type {
        if (!isNaN(parseFloat(c))) return Type.number;
        if (c.toLowerCase() == c.toUpperCase()) return Type.letter;
        if (c == '+' || c == '-' || c == '*' || c == '/') return Type.operator;
        if (c == ' ') return Type.white;
    }
}


parseExpression('2 + 2');