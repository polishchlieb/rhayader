var Type;
(function (Type) {
    Type[Type["operator"] = 0] = "operator";
    Type[Type["string"] = 1] = "string";
    Type[Type["number"] = 2] = "number";
})(Type || (Type = {}));
function parsePrimitive(expression) {
    if (expression.type == Type.number)
        return expression.value;
}
function parseExpression(expression) {
    var current = [];
    if (expression.value == '+') {
        current = expression.children.reduce(function (acc, curr) {
            return acc + parsePrimitive(curr);
        }, 0);
    }
    console.log(current);
}
var expression = {
    type: Type.operator,
    value: '+',
    children: [
        {
            type: Type.number,
            value: 2
        },
        {
            type: Type.number,
            value: 2
        }
    ]
};
parseExpression(expression);
