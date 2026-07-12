# Project Polaris Vector REPL

An interactive C++ utility for experimenting with vectors in R2 and R3. When
GNU Readline is available, previous commands can be recalled and edited with
the Up and Down arrow keys. History is saved between sessions in
`~/.polaris_vector_history`.

## Build and test

A C++17 compiler and CMake 3.16 or newer are required. GNU Readline development
files are optional; without them, the REPL builds without history and line
editing support.

```sh
cmake -S software/vector-repl -B build/vector-repl
cmake --build build/vector-repl
ctest --test-dir build/vector-repl --output-on-failure
```

## Run

```sh
./build/vector-repl/vector-repl
```

Example session:

```text
polaris> vector a 1 2 3
a = (1, 2, 3)
polaris> vector b 4 5 6
b = (4, 5, 6)
polaris> magnitude a
3.74165738677394
polaris> add a b
(5, 7, 9)
polaris> scale a 2
(2, 4, 6)
polaris> dot a b
32
polaris> cross a b
(-3, 6, -3)
```

Type `help` in the REPL for the complete command list. Operations requiring
two vectors reject mixed dimensions, and cross product is restricted to R3.
