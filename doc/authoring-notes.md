# Authoring notes

Course notes live below `notes/`, grouped into subject directories. Use a
numeric filename prefix when ordering matters because the combined book sorts
source paths lexically.

## Front matter

Each structured course note starts with YAML metadata:

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

The fields capture both the subject and its provenance:

- `title` is the note's topic and document title.
- `course` identifies the broader course or area of study.
- `unit` records its order within that course.
- `provider` records the original learning provider.
- `author` and `date` record when the note entered the knowledge base.

Begin the note body with its first top-level heading. Shared layout and PDF
presentation belong in `pandoc/`, not in individual note files.

## Mathematics

Use Pandoc Markdown with LaTeX math delimiters. Inline mathematics uses single
dollar signs, and display mathematics uses a pair:

```markdown
The vector $\vec v$ belongs to $\mathbb R^n$.

$$
\lVert\vec v\rVert=\sqrt{v_1^2+\cdots+v_n^2}
$$
```

The shared LaTeX header also provides `\blueD`, `\maroonD`, `\greenD`,
`\redD`, and `\goldD` for semantic color accents in equations.

## Images and figures

Keep reusable rendered images in `images/`. Editable image sources belong in a
source subdirectory such as `images/source/`, while GeoGebra sources belong in
`geogebra/`.

Pandoc figure identifiers make cross-references stable:

```markdown
[@fig:vector-addition] illustrates head-to-tail vector addition.

![Head-to-tail vector addition.](../../images/vectors-2d-addition.png){#fig:vector-addition width=70mm}
```

Use a unique `fig:` identifier and meaningful alternative text. The shared
`pandoc-crossref` configuration renders the reference and figure number.

## Checking a new note

Use `make list` to confirm that the note appears in the intended position. Then
run `make` to build its individual PDF and `make book` to check its placement in
the combined volume. Generated PDFs remain under `build/` and should not be
committed.

Markdown lint configuration is stored in `.markdownlint.json`. The repository
allows duplicate headings and does not enforce sibling heading increments,
which suits long-form technical notes.
