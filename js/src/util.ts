export function times(str: string, multiplier: number): string {
    let output: string = '';
    for (let i = 0; i < multiplier; ++i) {
        output += str;
    }
    return output;
}