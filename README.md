# Project Polaris Academy
Engineering notebook and learning companion throughout my Master of Science in Aerospace Engineering.

## Abstract
Project Polaris Academy is a curated collection of learning resources assembled to support my Master's studies in Aerospace Engineering at UiT Narvik. I was accepted as a student at UiT Narvik at the Aerospace Engineering Master, part-time online programme starting in August 2026. This document must be understood as an aid for me personally, it is never meant to be published and will consist of various courses I find interesting and/or heplfull to achieve a wider understanding in the fields.

/jole

## Building the notes

The PDF toolchain uses Pandoc and XeLaTeX. Build every weekly note as a
separate PDF with:

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

- [Vector REPL](software/vector-repl/README.md) — create vectors in R2 and R3
  and interactively calculate magnitudes, sums, scalar multiples, dot products,
  and cross products.

A note can provide document metadata at the top of the Markdown file:

```yaml
---
title: Week 28, 2026
subtitle: Multivariable calculus
author: Jon Leithe
date: July 2026
---
```
