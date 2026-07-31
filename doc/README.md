# Project documentation

Project Polaris Academy is a long-term aerospace-engineering knowledge base. It
produces individual PDF and HTML notes, combined subject PDFs, and a complete
Academy volume. Selected HTML material is intended for later publication on
`jonleithe.no`.

The repository also contains `r-vec`, a small command-line program for
experimenting with vectors in finite-dimensional real coordinate spaces.

## Documentation map

- [Getting started](getting-started.md) explains prerequisites, common commands,
  and generated output.
- [Authoring notes](authoring-notes.md) defines portable Markdown, metadata,
  mathematics, figures, equations, page breaks, and validation conventions.
- [Build system](build-system.md) explains how Make and Quarto produce the
  current outputs.
- [`r-vec`](r-vec.md) documents how to build, test, run, and use the vector REPL.

Repository-wide context also lives in:

- [`AGENTS.md`](../AGENTS.md), for instructions to repository-aware assistants;
- [`AUTHOR.md`](../AUTHOR.md), for the maintainer's background and preferences;
- [`PROJECT_HISTORY.md`](../PROJECT_HISTORY.md), for durable decisions and
  milestones.

## Repository map

| Path | Purpose |
| --- | --- |
| `notes/` | Portable Markdown course-note sources |
| `resources/` | Curated links and supporting subject references |
| `images/` | Rendered note images and combined-book artwork |
| `geogebra/` | GeoGebra source files for mathematical diagrams |
| `pandoc/` | Shared filters, metadata, and LaTeX presentation |
| `_quarto.yml` | Multi-format configuration and configured note list |
| `index.md` | Shared Quarto book home page and preface |
| `software/r-vec/` | C++ vector library, parser, REPL, and tests |
| `fonts/` | Fonts used by PDF templates |
| `build/` | Ignored Quarto, Pandoc, and CMake output |

The root [README](../README.md) gives the short project overview. These pages are
the operational reference for maintaining and extending the repository.
