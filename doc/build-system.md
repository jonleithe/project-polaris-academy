# Notes build system

Quarto produces individual PDF and HTML documents as well as combined PDF
books. GNU Make provides one stable command interface for these outputs.

Run `make help` from the repository root for the current target summary.

## Individual PDFs

Render one note with:

```sh
make note NOTE=linear-algebra/courses/khan-academy/01-vectors-and-spaces.md
```

`NOTE` may be relative to `notes/`, may begin with `notes/`, or may be a unique
filename found below `notes/`. Ambiguous or missing names fail with an explicit
error.

Render every note discovered by `_quarto-notes.yml` with:

```sh
make notes
```

The default `make` target is equivalent to `make notes`. Quarto writes these
PDFs below `build/quarto/` while preserving their paths, for example:

```text
build/quarto/notes/linear-algebra/courses/khan-academy/01-vectors-and-spaces.pdf
```

## HTML documents

Render the root home page and the notes below `notes/personal/` as HTML with:

```sh
make site
```

Output is written below `build/site/`. The site profile provides sidebar
navigation, search, and previous/next page links. Other note trees remain
available to the individual and subject builds but are excluded from the site.

Start a live local preview with:

```sh
make preview
```

## Combined PDFs

Render the numbered Khan linear algebra notes as one PDF with:

```sh
make linear-algebra
```

The Linear Algebra book profile is `_quarto-linear-algebra.yml`. Its output is:

```text
build/books/linear-algebra/project-polaris-linear-algebra.pdf
```

Render the Markdown notes below `notes/personal/` as the Academy volume with:

```sh
make book
```

The complete Academy metadata profile is `_quarto-book.yml`. Before rendering,
`make book` runs `scripts/generate-book-profile.py` to discover every Markdown
file below `notes/personal/`. The script writes the ordered chapter list to the
ignored `_quarto-auto-book.yml` profile, which Quarto merges with the metadata
profile. Its output is:

```text
build/books/academy/project-polaris-notes.pdf
```

Personal-note chapters use deterministic path order, so directory and filename
prefixes control their sequence without manual configuration. The Linear
Algebra subject profile keeps an explicit chapter list so its scope and
pedagogical order remain intentional. Separate output directories prevent one
Quarto book build from cleaning the other book or `build/r-vec/`. The root
`index.md` provides the shared home page and unnumbered preface required by
Quarto books. When a note defines `course` in its YAML front matter, the
complete book prefixes its chapter title with that value, for example
`MAT3800 Linear Algebra II — Systems of Equations`. Standalone note and website
titles remain unchanged.

## Configuration and presentation files

| File | Responsibility |
| --- | --- |
| `_quarto.yml` | Shared project, HTML, and PDF settings |
| `_quarto-notes.yml` | Automatic discovery for the all-notes PDF build |
| `_quarto-linear-algebra.yml` | Linear Algebra book metadata, chapters, and output |
| `_quarto-book.yml` | Academy book metadata and output |
| `_quarto-site.yml` | Personal-notes site scope, navigation, and output |
| `scripts/generate-book-profile.py` | Generated personal-note book chapter discovery |
| `pandoc/book-course-chapters.lua` | Complete-book course prefixes for chapter titles |
| `Makefile` | Stable commands for Quarto outputs |
| `index.md` | Required home page and shared preface for Quarto books |
| `pandoc/polaris.tex` | Shared PDF styling, headers, footers, and colour commands |
| `pandoc/book-title.tex` | Complete-volume cover composition and fonts |
| `pandoc/pagebreak.lua` | Portable `<!-- pagebreak -->` handling |

Keep presentation logic in these shared files. Notes should contain metadata
and content rather than format-specific page setup.

## Cleaning

```sh
make clean
```

This removes PDF files below `build/` and the Quarto `build/quarto/`,
`build/site/`, and `build/books/` trees. It leaves non-PDF CMake output such as
`build/r-vec/` intact. The complete `build/` directory is ignored by Git.
