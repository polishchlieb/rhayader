import { tempVariables } from "./globals"

const setTempVariable = (name: string, value: string) => {
    tempVariables[name] = value;
}

const removeTempVariable = (name: string) => {
    delete tempVariables[name];
}

export {
    setTempVariable,
    removeTempVariable
}