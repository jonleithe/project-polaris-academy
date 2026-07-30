# Project Polaris History

This file records durable context and decisions from AI-assisted project work.
It contains concise summaries rather than verbatim chat transcripts. The newest
entry should be added at the top of the history.

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
