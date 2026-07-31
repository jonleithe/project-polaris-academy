# Authoring notes

Course notes live below `notes/`, organized first by subject and then by course.
Course-derived material belongs in `notes/<subject>/courses/<course>/`, while
future subject-level synthesis belongs in `notes/<subject>/reference/`. Write
notes in portable Quarto Markdown so the same source can produce a readable PDF
and HTML page and can later become part of a combined book.

Use a two-digit numeric filename prefix where order matters:

```text
notes/linear-algebra/courses/khan-academy/01-vectors-and-spaces.md
```

The number controls lexical ordering within a course. Use lowercase words
separated by hyphens after the prefix. Do not repeat the provider in every
filename when the course directory already identifies it. Include a course
identifier where needed, for example `courses/mit-ocw-18-06/`.

## Front matter

Each structured course note starts with YAML metadata:

```yaml
---
title       : Vectors and Spaces
subject     : Linear Algebra
course      : Linear Algebra
unit        : 1
provider    : Khan Academy
author      : Jon Leithe
date        : 2026-07-20
---
```

The fields capture both the subject and its provenance:

- `title` is the note's topic and document title.
- `subject` identifies the broader field used to organize the knowledge base.
- `course` identifies the broader course or area of study.
- `unit` records its order within that course.
- `provider` records the original learning provider.
- `author` identifies the note's author.
- `date` uses ISO `YYYY-MM-DD` format so Quarto, Pandoc, and Hugo interpret it
  consistently.

In a Quarto book, the YAML `title` becomes the chapter heading. Begin body
sections at level two so they remain within that chapter. Quarto promotes them
appropriately when rendering the note as a standalone document. Shared layout
and format configuration belong in `_quarto.yml` and `pandoc/`, not in
individual notes.

## Headings and ordinary Markdown

Use ATX headings and semantic Markdown:

```markdown
## Vectors

### Addition

#### Worked example
```

Use ordinary Markdown for paragraphs, emphasis, lists, links, block quotes,
tables, and fenced code blocks. Avoid raw HTML when normal Markdown or Quarto
syntax can express the same idea, because raw HTML is normally omitted from PDF
output. Avoid raw LaTeX outside mathematics for the corresponding reason.

## Mathematics

Inline mathematics uses single dollar signs, and display mathematics uses a
pair:

```markdown
The vector $\vec v$ belongs to $\mathbb R^n$.

$$
\lVert\vec v\rVert=\sqrt{v_1^2+\cdots+v_n^2}
$$
```

Prefer commands supported by both XeLaTeX and MathJax. When a note uses the
shared semantic colour commands, define their HTML equivalents once near the
top of that note in a hidden block:

```markdown
::: {.hidden}
$$
\def\blueD#1{\color{blue}{#1}}
\def\maroonD#1{\color{maroon}{#1}}
\def\greenD#1{\color{green}{#1}}
\def\redD#1{\color{red}{#1}}
\def\goldD#1{\color{orange}{#1}}
$$
:::
```

The LaTeX versions live in `pandoc/polaris.tex`. Keeping the MathJax definitions
in the Markdown makes the same expressions work in HTML without exposing the
definition block in rendered output.

## Equations and cross-references

Use Quarto-compatible `eq-` identifiers and refer to them with `@eq-...`:

```markdown
The magnitude relation is shown in @eq-vector-magnitude.

$$ {#eq-vector-magnitude}
\lVert\vec v\rVert^2 = \vec v \cdot \vec v
$$
```

Identifiers must be unique within a rendered document. Use descriptive names
rather than numbering labels manually.

## Images and figures

Keep reusable rendered images in `images/`. Editable image sources belong in a
source subdirectory such as `images/source/`, while GeoGebra sources belong in
`geogebra/`.

Use Quarto-compatible `fig-` identifiers:

```markdown
@fig-vector-addition illustrates head-to-tail vector addition.

![Head-to-tail vector addition.](../../../../images/vectors-2d-addition.png){#fig-vector-addition width=70%}
```

Use meaningful alternative text, a useful caption, and a unique identifier.
Relative image paths are resolved from the note's directory. Percentage widths
are generally portable between HTML and PDF; use format-specific sizing only
when the two outputs genuinely require it.

## Page breaks

Use the portable page-break marker:

```markdown
<!-- pagebreak -->
```

The Lua filter converts it to a page break for PDF output, while HTML treats it
as an invisible comment. Do not place `\newpage` directly in a note.

## Adding a note to configured builds

The root `_quarto.yml` currently lists rendered notes explicitly. After adding
a source file:

1. Add its path to `project.render` in `_quarto.yml`.
2. Run `make list` to check its lexical position among all note sources.
3. Render it directly with `make note NOTE=<subject>/<filename>.md`.
4. Run `make notes` to check every configured PDF.
5. Run `make site` to check the HTML rendition.
6. When relevant, run `make linear-algebra` or `make book` to check combined
   output.

For example:

```sh
make note NOTE=linear-algebra/courses/khan-academy/01-vectors-and-spaces.md
```

`NOTE` may also contain a path beginning with `notes/` or a unique filename.
Run `make help` for the complete command summary.

## Authoring checklist

Before considering a note ready:

- confirm the YAML parses and the date uses ISO format;
- check heading order and terminology;
- verify mathematical notation in both PDF and HTML;
- check every figure, equation reference, link, and image;
- confirm page breaks improve the PDF without affecting HTML;
- keep generated files below `build/` and out of Git;
- run the Markdown linter where available.

Markdown lint configuration is stored in `.markdownlint.json`. The repository
allows duplicate headings and does not enforce sibling heading increments,
which suits long-form technical notes.
