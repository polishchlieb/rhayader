export interface Function {
    name: string;
    execute(args: string[], commandArgs: string[]): void;
}