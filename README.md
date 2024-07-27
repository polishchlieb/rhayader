# rhayader
Functional programming language interpreter written in C++

# Building
Use CMake to build, for example (on Linux with gcc):
- `cmake`
- `make`

# Running
- `rhayader (file name)` to run a file
- `rhayader` to use REPL (Really Epic Program Launcher)

# FizzBuzz
```
for i in Array.range(1, 101) {
  if Math.mod(i, 15) == 0
    IO.print('FizzBuzz')
  else if Math.mod(i, 3) == 0
    IO.print('Fizz')
  else if Math.mod(i, 5) == 0
    IO.print('Buzz')
  else
    IO.print(i)
}
```