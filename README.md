# Project Polaris Academy

Engineering notebook and learning companion throughout my Master of Science in
Aerospace Engineering.

## Abstract

Project Polaris Academy is a curated collection of learning resources supporting
my master's studies in Aerospace Engineering at UiT Narvik. I was accepted into
the part-time online master's programme beginning in August 2026. This repository
is a personal study aid containing courses, notes, and resources that help me
develop a broader understanding of aerospace engineering and related fields. It
is intended for personal use and is not meant for publication.

/jole

## Documentation

See the [project documentation](doc/README.md) for setup, repository structure,
note authoring, build internals, and the `r-vec` command-line tool.

## Building the notes

The PDF toolchain requires:

- GNU Make
- Pandoc
- [`pandoc-crossref`](https://lierdakil.github.io/pandoc-crossref/)
- XeLaTeX with the LaTeX packages used by the templates, including `etoolbox`,
  `fancyhdr`, `fontspec`, `tikz`, `titlesec`, and `xcolor`

Build every note as a separate PDF with:

```sh
make
```

Build the combined knowledge-base volume with:

```sh
make book
```

Generated files are written to `build/`. Shared PDF presentation is configured
in `pandoc/defaults.yaml` and `pandoc/polaris.tex`; note files should contain
only their metadata and content.

## Helper software

- [r-vec](software/r-vec) — create vectors in finite-dimensional real
  coordinate spaces, inspect their dimensions, and evaluate sums and differences.

## Writing notes

Structured course notes begin with YAML metadata identifying the topic, its
place in the course, and the original learning provider. For example:

```yaml
---
title       : Vectors and Spaces
course      : Linear Algebra
unit        : 1
provider    : Khan Academy
author      : Jon Leithe
date        : July 2026
---
```

The `title` names the topic covered by the note. The `course`, `unit`, and
`provider` fields preserve its learning context, while `author` and `date`
record when it became part of this knowledge base.
