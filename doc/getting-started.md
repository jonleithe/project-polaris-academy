# Getting started

Run all commands from the repository root.

## Notes prerequisites

The multi-format notes toolchain requires:

- GNU Make;
- Quarto;
- XeLaTeX;
- the LaTeX packages used by the shared templates, including `cancel`,
  `etoolbox`, `fancyhdr`, `fontspec`, `tikz`, `titlesec`, and `xcolor`.

Confirm the available Make targets with:

```sh
make help
```

## Common notes commands

Render one PDF:

```sh
make note NOTE=linear-algebra/courses/khan-academy/01-vectors-and-spaces.md
```

Render all configured individual PDFs:

```sh
make notes
```

Render the combined Linear Algebra PDF or complete Academy PDF:

```sh
make linear-algebra
make book
```

Render or preview HTML:

```sh
make site
make preview
```

List all Markdown note sources or clean generated note output:

```sh
make list
make clean
```

## Generated notes files

All generated output belongs below `build/`, which Git ignores.

| Output | Path |
| --- | --- |
| Individual Quarto PDFs | `build/quarto/notes/<subject>/courses/<course>/<note>.pdf` |
| Quarto HTML documents | `build/site/notes/<subject>/courses/<course>/<note>.html` |
| Combined Linear Algebra PDF | `build/books/linear-algebra/project-polaris-linear-algebra.pdf` |
| Complete Academy PDF | `build/books/academy/project-polaris-notes.pdf` |

The HTML output is not yet the final structured `/notes/` website artifact; see
[the build-system guide](build-system.md) for the current boundary.

## `r-vec` prerequisites

Building `r-vec` requires:

- CMake 3.16 or newer;
- a C++17 compiler;
- CTest, normally installed with CMake;
- GNU Readline headers and library for command history and line editing
  (optional).

Without Readline, `r-vec` still builds and runs with a basic input prompt.

Build the vector REPL:

```sh
./make-r-vec
```

Run its tests and then launch it:

```sh
ctest --test-dir build/r-vec --output-on-failure
./build/r-vec/r-vec
```

The CMake build is written to `build/r-vec/`.
