# Getting started

Run all commands from the repository root.

## Prerequisites

Building the notes requires:

- GNU Make
- Pandoc
- `pandoc-crossref`
- XeLaTeX
- the LaTeX packages used by the templates, including `etoolbox`, `fancyhdr`,
  `fontspec`, `tikz`, `titlesec`, and `xcolor`

Building `r-vec` requires:

- CMake 3.16 or newer
- a C++17 compiler
- CTest, normally installed with CMake
- GNU Readline headers and library for command history and line editing
  (optional)

Without Readline, `r-vec` still builds and runs with a basic input prompt.

## Common commands

Build every Markdown note as a separate PDF:

```sh
make
```

Build the combined knowledge-base volume:

```sh
make book
```

List note sources in their build order:

```sh
make list
```

Remove generated PDFs while preserving other build output:

```sh
make clean
```

Build the vector REPL:

```sh
./make-r-vec
```

Run its tests and then launch it:

```sh
ctest --test-dir build/r-vec --output-on-failure
./build/r-vec/r-vec
```

## Generated files

All generated output belongs under `build/`, which Git ignores. Individual PDF
paths mirror their note paths. For example:

```text
notes/linear-algebra/01-khan-vectors-and-spaces.md
    -> build/linear-algebra/01-khan-vectors-and-spaces.pdf
```

The combined volume is written to:

```text
build/project-polaris-notes.pdf
```

The CMake build for `r-vec` is written to `build/r-vec/`.
