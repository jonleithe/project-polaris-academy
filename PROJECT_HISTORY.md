# Project Polaris History

This file records durable context and decisions from AI-assisted project work.
It contains concise summaries rather than verbatim chat transcripts. The newest
entry should be added at the top of the history.

## 2026-09-22 — Added Chapter 4.1 on vector spaces and subspaces

- Converted the handwritten `4-1-vector-spaces-and-subspaces.pdf` into the
  personal chapter `4-1-vector-spaces-and-subspaces.md`.
- Covered the vector-space axioms, the subspace test, the fact that every span
  is a subspace, and two worked span-membership examples.
- Replaced the obsolete Chapter 4.1 theorem-index placeholder with **Every
  Span Is a Subspace** and linked it to the new source note.

## 2026-09-20 — Returned published outputs to personal notes only

- Removed the remaining Khan Academy Linear Algebra notes from the Academy
  book and website. They remain available as source material and in the
  broader all-notes build.
- Restored the published order to the root front page, theorem index, and all
  personal notes in deterministic path order. The generated book profile and
  site sidebar still derive from that single ordered list.

## 2026-09-20 — Moved vector foundations into the personal published sequence

- Removed Khan Academy Unit 01, `01-vectors-and-spaces.md`, from the Academy
  book and website while retaining it in the repository and broader all-notes
  build.
- Added the new personal Chapter 1.3, `1-3-vector-equations.md`, to the
  automatically discovered personal sequence after moving the relevant
  foundational material into it.
- The generated book chapter list and website sidebar continue to derive from
  the same source order: home page, theorem index, Khan Academy units 02–05,
  then all personal notes in path order.

## 2026-09-19 — Reframed Chapter 2.8 around subspaces

- Made the new handwritten `2-8-subspaces-of-Rn.pdf` the primary source for
  Chapter 2.8 and retitled the rendered note **Subspaces of $\mathbb{R}^n$**.
- Expanded the chapter from a column/null-space treatment to cover the
  subspace test, spans, bases, column space, and null space in that pedagogical
  order. Retained the earlier handwritten note's sinusoidal-function example
  and engineering interpretation.
- Updated the theorem index and internal links for the renamed Markdown source
  `2-8-subspaces-of-Rn.md`.
- Audited the remaining handwritten linear-algebra scans against their
  corresponding Markdown notes. The existing notes cover the source material;
  corrected the matrix-multiplication compatibility condition from a reversed
  prose statement to “columns of $A$ equal rows of $B$.”

## 2026-09-18 — Incorporated handwritten column and null space notes

- Converted the eight-page `notes/hand-written/column-and-null-space.pdf`
  into the personal chapter `2-8-column-and-null-space.md`, automatically
  included before Dimension and Rank in the book and site.
- Consolidated repeated examples, corrected arithmetic and notation slips,
  and retained the original scan. Added the principal results to the theorem
  index and linked the related Dimension and Rank chapter.

## 2026-09-15 — Standardized book illustration backgrounds

- Revised all seven diagrams referenced by personal notes to use white paper
  and a very faint square grid, with roughly centimetre-scale spacing in PDF.
- Retained the hand-drawn diagrams and original assets, updated note references,
  and recorded the edit prompts in `images/source/personal-white-grid-prompts.md`.
- Documented the convention in the authoring guide; reproduced textbook covers
  and photographs keep their original appearance.
- Extended the same hand-drawn, white-paper treatment to all nine diagrams in
  Khan Academy units 01–05 and the book's four cover sketches. Coordinate grids
  follow mathematical ticks; the cover grid uses 10 mm spacing.
- Corrected the 3D angle marker to sit between its two vectors and removed an
  incorrect guide line from the vector-projection illustration. Recorded the
  book-wide review and final prompts in `images/source/book-white-grid-prompts.md`.

## 2026-09-12 — Added the foundational Khan Academy sequence to published outputs

- Expanded the complete Academy book and navigable site to include Khan Academy
  Linear Algebra units 01–05 alongside the personal collection.
- Established the shared order: root front page, theorem index, the five Khan
  Academy units, then the remaining personal notes. This keeps the theorem
  reference at the beginning while presenting foundational course material
  before personal extensions.
- Generate both the book chapter list and site sidebar from the same ordered
  source list, so new personal notes remain discoverable without the two
  outputs drifting apart. Khan Academy units 06–07 remain outside this published
  collection for now.

## 2026-08-16 — Made personal notes the published collection

- Scoped `make book` chapter discovery to Markdown files below
  `notes/personal/`, while retaining the root `index.md` as the book preface.
- Scoped `make site` and `make preview` rendering and sidebar discovery to the
  same personal-notes tree, while retaining the existing home page.
- Moved all-notes discovery into a dedicated Quarto profile so `make notes`
  retains its existing scope without leaking course notes into the site build.
- Left individual-note, all-notes, and subject-book builds unchanged so course
  and reference material remains available outside the personal collection.

## 2026-08-10 — Automated complete-book chapter discovery

- Replaced the complete Academy book's manually maintained chapter list with a
  generated Quarto profile containing every Markdown file below `notes/`.
- Kept `make book` as the stable interface and made it regenerate the chapter
  profile in deterministic path order before rendering.
- Used each note's optional `course` front-matter field to prefix complete-book
  chapter titles without changing standalone PDF or website titles.
- Left subject-book chapter lists explicit so their scope and pedagogical order
  remain intentional.

## 2026-08-01 — Unified reusable math definitions across HTML and PDF

- Added a focused Pandoc filter that retains `\def` for MathJax while promoting
  definitions in explicitly marked math-definition blocks to `\gdef` for
  LaTeX, keeping each reusable equation definition in one source location.
- Added the root `index.md` to the default Quarto render list and introduced a
  dedicated HTML-site profile with sidebar navigation, search, and previous/next
  page links. The site and preview targets now use that profile.
- Verified the navigable eight-page HTML site, the vector
  dot-and-cross-product note as an individual PDF, and the complete Academy PDF
  book.

## 2026-07-31 — Organized notes by subject and course

- Introduced the scalable `notes/<subject>/courses/<course>/` hierarchy for
  course-derived notes and reserved `notes/<subject>/reference/` for future
  subject-level synthesis.
- Moved the Khan Academy Linear Algebra notes to
  `notes/linear-algebra/courses/khan-academy/`.
- Removed the redundant `khan-` filename prefix and added explicit `subject`
  metadata while preserving provider and course provenance.
- Updated Quarto profiles, Make examples, image paths, and documentation for the
  new hierarchy.

## 2026-07-31 — Completed the combined-PDF migration to Quarto

- Added separate Quarto book profiles for the Linear Algebra volume and the
  complete Project Polaris Academy volume.
- Changed `make linear-algebra` and `make book` to render the corresponding
  Quarto profiles while preserving the established Make interface.
- Isolated the book output directories so Quarto cannot clean the other book or
  the CMake output below `build/r-vec/`.
- Removed the obsolete direct-Pandoc defaults and book metadata, eliminating the
  project's dependency on `pandoc-crossref`.

## 2026-07-31 — Aligned documentation with the Quarto migration

- Rewrote the note-authoring guide around portable Quarto Markdown, ISO dates,
  cross-format mathematics, Quarto figure and equation identifiers, portable
  page breaks, and PDF/HTML validation.
- Updated the README, documentation index, getting-started guide, and build
  guide to describe the implemented Make interface and transitional division
  between Quarto output and combined Pandoc PDFs.
- Updated repository and author context that still described the project as
  Pandoc-only.
- Preserved the future boundary in which the Academy produces a stable HTML
  artifact and `jonleithe.no` owns website assembly and deployment.

## 2026-07-31 — Added a stable Make interface for multi-format output

- Added `make help` as the discoverable command reference.
- Added explicit single-note rendering with `make note NOTE=...` and configured
  batch rendering with `make notes`.
- Added targets for the combined Linear Algebra PDF, complete Academy PDF, HTML
  output, and live preview.
- Initially kept Quarto responsible for individual PDF and HTML documents while
  retaining the working Pandoc pipeline for combined PDFs during the migration.

## 2026-07-31 — Began the Quarto multi-format publishing migration

- Added a Quarto project configuration for rendering the seven current Khan
  Academy linear algebra notes as both HTML and PDF.
- Converted the notes from Pandoc-specific constructs to portable Quarto
  Markdown, including ISO dates, page breaks, equations, figure labels, and
  cross-references.
- Preserved the existing XeLaTeX styling through `pandoc/polaris.tex` and
  retained MathJax-compatible colour macros in notes that use them.
- Confirmed successful generation of all seven PDFs and all seven HTML pages,
  including resolved figure and equation references and copied image assets.

## 2026-07-30 — Adopted a main-first Git workflow

- Merged `agent/add-project-context-and-update-notes` into `main`.
- Established that routine work should be committed directly to `main`.
- Separate branches should be created only when the maintainer explicitly
  requests one.

## 2026-07-28 — Project context connected across ChatGPT and VS Code

- Established that AI assistants in VS Code do not automatically have access
  to previous ChatGPT browser conversations.
- Added the browser-side Project Polaris brief as `AGENTS.md`, making the
  project's goals, philosophy, writing standards, tooling, roadmap, and author
  context available to repository-aware agents.
- Created `PROJECT_HISTORY.md` for durable, dated summaries of important
  conversations and decisions.
- Reviewed the repository structure and documentation. Confirmed that the two
  principal technical outputs are the Pandoc/XeLaTeX study-note collection and
  the C++ `r-vec` learning tool.
- Confirmed that the current C++ project builds successfully and that both the
  vector and parser test suites pass.
- Confirmed that the combined PDF knowledge base builds successfully.
- Preserved the existing uncommitted note edits. These primarily introduce a
  shared Khan chapter hierarchy; `notes/matrices/note1.md` remains a small
  work-in-progress note.
