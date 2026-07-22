# PDF build system

The root `Makefile` discovers Markdown files recursively below `notes/` and
maps each one to a PDF below `build/`. The relative directory and base filename
are preserved.

## Individual notes

The default `make` target builds every discovered note. Each PDF depends on:

- its Markdown source;
- `pandoc/defaults.yaml`; and
- `pandoc/polaris.tex`.

Pandoc uses XeLaTeX, numbered sections, a table of contents, syntax highlighting,
the `pandoc-crossref` filter, and the page-break Lua filter. The resource search
path includes the repository root, `notes/`, `images/`, and all note
subdirectories.

Because Make tracks these dependencies, an unchanged PDF is not rebuilt unless
its source or shared presentation configuration is newer.

## Combined volume

`make book` passes all note sources to one Pandoc invocation in lexical path
order. It adds:

- `pandoc/book.yaml` for the volume title, subtitle, author, and date;
- `pandoc/book-title.tex` for the custom cover; and
- the `images/book-cover-*.png` artwork.

The output is `build/project-polaris-notes.pdf`. Prefix filenames numerically
inside each subject directory to control their relative order.

## Presentation files

| File | Responsibility |
| --- | --- |
| `pandoc/defaults.yaml` | Pandoc, PDF engine, filter, page, color, and resource defaults |
| `pandoc/polaris.tex` | Shared section styling, headers, footers, title page, and color commands |
| `pandoc/book.yaml` | Combined-volume metadata |
| `pandoc/book-title.tex` | Combined-volume cover composition and font selection |
| `pandoc/pagebreak.lua` | Page-break handling during Pandoc conversion |

Change shared styling in these files so individual notes remain focused on
content. After changing a template, rebuild both an individual note and the
book to check headings, cross-references, page breaks, and the cover.

## Cleaning

`make clean` deletes only PDF files below `build/`. It intentionally leaves
CMake output and other generated files intact. The complete `build/` directory
is ignored by Git.
