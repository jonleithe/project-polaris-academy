# Project documentation

Project Polaris Academy is a personal aerospace-engineering knowledge base. Its
primary output is a collection of PDF notes, available either as individual
documents or as one combined volume. The repository also contains `r-vec`, a
small command-line program for experimenting with vectors in finite-dimensional
real coordinate spaces.

## Documentation map

- [Getting started](getting-started.md) explains the prerequisites, common
  commands, and repository layout.
- [Authoring notes](authoring-notes.md) describes note metadata, organization,
  mathematics, figures, and cross-references.
- [Build system](build-system.md) explains how Make and Pandoc produce the PDFs
  and where presentation settings live.
- [`r-vec`](r-vec.md) documents how to build, test, run, and use the vector REPL.

## Repository map

| Path | Purpose |
| --- | --- |
| `notes/` | Structured Markdown course notes and the source of the PDFs |
| `resources/` | Curated links and supporting subject references |
| `images/` | Images used by notes and by the combined book cover |
| `geogebra/` | GeoGebra source files for mathematical diagrams |
| `pandoc/` | Shared Pandoc metadata, Lua filters, and LaTeX presentation |
| `software/r-vec/` | C++ vector library, parser, REPL, and tests |
| `fonts/` | Fonts embedded by the PDF templates |
| `build/` | Generated PDFs and CMake output; ignored by Git |

The root [README](../README.md) gives the short project overview. These pages
are the operational reference for maintaining and extending the repository.
