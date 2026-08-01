# Project Polaris History

This file records durable context and decisions from AI-assisted project work.
It contains concise summaries rather than verbatim chat transcripts. The newest
entry should be added at the top of the history.

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
