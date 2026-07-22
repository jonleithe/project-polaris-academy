# `r-vec`

`r-vec` is an interactive C++17 program for creating and manipulating vectors
in finite-dimensional real coordinate spaces. It accepts vectors in
`R^n` for any `n >= 1`, rejects non-finite components, and requires equal
dimensions for addition and subtraction.

## Build and test

The repository helper configures and builds the default CMake configuration:

```sh
./make-r-vec
```

The equivalent explicit commands, including a debug build type, are:

```sh
cmake -S software/r-vec -B build/r-vec -DCMAKE_BUILD_TYPE=Debug
cmake --build build/r-vec
ctest --test-dir build/r-vec --output-on-failure
```

CMake creates the following targets:

- `rvec`, the vector value library;
- `rvec_parser`, the tokenizer and command parser;
- `r-vec`, the interactive executable;
- `rvec-tests`, the vector-library tests; and
- `parser-tests`, the tokenizer and parser tests.

If GNU Readline is available, the executable enables line editing and stores
history in `~/.polaris_rvec_history`. Otherwise it uses standard input without
persistent history.

## Run

```sh
./build/r-vec/r-vec
```

An example session:

```text
polaris> vector a(1, 2, 3)
a = (1, 2, 3)
polaris> vector b(-1, 4, 0.5)
b = (-1, 4, 0.5)
polaris> a + b
(0, 6, 3.5)
polaris> vector difference = a - b
difference = (2, -2, 2.5)
polaris> dimension difference
3
polaris> quit
```

## Command reference

| Command | Result |
| --- | --- |
| `vector v(x1, x2, ..., xn)` | Create or replace a named vector |
| `a + b - c` | Evaluate an addition/subtraction expression |
| `vector v = a + b - c` | Evaluate an expression and store the result |
| `show name` | Print a stored vector |
| `dimension name` | Print a vector's dimension |
| `add first second` | Add two stored vectors |
| `list` | Print every stored vector and its coordinate space |
| `help` | Print command help |
| `quit` or `exit` | End the session |

Names begin with a letter or underscore and may then contain letters, digits,
or underscores. Components accept decimal and scientific notation with an
optional sign. Operations report an error for unknown names, invalid syntax,
non-finite values, empty vectors, or mismatched dimensions.

## Source layout

| Path | Purpose |
| --- | --- |
| `inc/RVec.h` and `src/RVec.cpp` | Vector representation and arithmetic |
| `inc/Parser.h` and `src/Parser.cpp` | Tokens, grammar, and parsed statements |
| `src/main.cpp` | REPL state, command execution, input, and output |
| `tests/RVecTests.cpp` | Vector invariants and arithmetic tests |
| `tests/ParserTests.cpp` | Tokenization, statements, expressions, and syntax-error tests |

When adding syntax, update the token and statement types, parser, executor, help
text, command table above, and parser tests together.
