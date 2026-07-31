# Project Polaris Academy

Project Polaris Academy is Jon Leithe's long-term engineering notebook and
learning companion for a part-time Master of Science in Aerospace Engineering
at UiT Narvik, beginning in August 2026.

The repository combines course notes, worked examples, references, diagrams,
and educational software. It is primarily a personal study and engineering
reference, while selected material may also be published on
[jonleithe.no](https://www.jonleithe.no/).

## Documentation

See the [project documentation](doc/README.md) for setup, note-authoring
conventions, build internals, repository structure, and the `r-vec` command-line
tool.

Repository context is recorded in [AGENTS.md](AGENTS.md), [AUTHOR.md](AUTHOR.md),
and [PROJECT_HISTORY.md](PROJECT_HISTORY.md).

## Building the notes

The notes use Quarto for individual PDF and HTML output and for combined book
PDFs. Quarto uses Pandoc internally and XeLaTeX as the PDF engine.

Show the complete command reference:

```sh
make help
```

Render one note or every configured note as PDF:

```sh
make note NOTE=linear-algebra/courses/khan-academy/01-vectors-and-spaces.md
make notes
```

Render combined PDFs:

```sh
make linear-algebra
make book
```

Render or preview HTML:

```sh
make site
make preview
```

Generated files are written below `build/` and are not committed.

## Writing notes

Write portable Quarto Markdown that renders correctly as both HTML and PDF. Use
ISO dates, semantic headings, standard LaTeX mathematics, Quarto `fig-` and
`eq-` cross-reference identifiers, and the shared page-break marker.

See [Authoring notes](doc/authoring-notes.md) for examples and the validation
checklist.

## Helper software

- [`r-vec`](software/r-vec) creates vectors in finite-dimensional real
  coordinate spaces, reports their dimensions, and evaluates vector arithmetic.
