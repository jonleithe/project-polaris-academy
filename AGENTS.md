# Project Polaris Academy — Agent Instructions

## Project Context

Before making substantial changes, consult:

- `AUTHOR.md` for the maintainer's background, preferences, and learning goals.
- `PROJECT_HISTORY.md` for durable architectural decisions and recent milestones.

Update `PROJECT_HISTORY.md` only when work introduces a significant decision,
milestone, or change in project direction.

# Project Polaris Academy

## Overview

Project Polaris Academy is a long-term personal engineering and academic knowledge base.

The project has four equally important goals:

1. Produce high-quality study notes for a Master's degree in Aerospace Engineering.
2. Build a reusable engineering reference library.
3. Improve software engineering skills by treating the notes as a real software project.
4. Publish selected material publicly on jonleithe.no.

The project is intentionally developed with professional software engineering practices rather than as a collection of Markdown files.

---

# Project Philosophy

The repository should resemble a real engineering project.

Priorities:

- correctness over speed
- readability over cleverness
- maintainability over shortcuts
- reproducible builds
- version controlled documentation
- everything automated where practical

Notes are expected to evolve over many years.

---

# Target Audience

Initially:

- the author

Eventually:

- engineering students
- future employers
- open-source community

---

# Writing Style

Notes should:

- explain *why*, not only *how*
- avoid unnecessary jargon
- introduce mathematical notation carefully
- include worked examples
- include intuitive explanations before formal proofs
- prefer diagrams where useful
- build concepts progressively

Avoid copying textbooks.

---

# Repository Structure

Current major sections include

```
notes/
    linear-algebra/
    matrices/

images/

pandoc/

build/

software/

resources/
```

The project will grow into additional engineering disciplines.

Expected future sections:

```
calculus/
physics/
mechanics/
orbital-mechanics/
signals/
control/
gnss/
vlbi/
slr/
embedded/
cpp/
python/
linux/
```

---

# Build System

The notes use Quarto behind a GNU Make interface. Quarto uses Pandoc internally
and XeLaTeX for PDF output.

Important components:

- `Makefile` for stable user-facing commands;
- `_quarto.yml` for configured individual PDF and HTML builds;
- `_quarto-linear-algebra.yml` and `_quarto-book.yml` for combined PDFs;
- `book-title.tex` for the complete volume's custom cover.

Important commands include:

```
make help
make note NOTE=linear-algebra/courses/khan-academy/01-vectors-and-spaces.md
make notes
make linear-algebra
make book
make site
make preview
```

Quarto produces individual PDF and HTML documents as well as combined subject
and complete-book PDFs. Keep the Make target names stable if the underlying
profiles evolve.

XeLaTeX is used as PDF engine.

---

# Markdown Style

Use:

- ATX headings
- fenced code blocks
- LaTeX math
- internal links where appropriate

Display math:

```
$$
...
$$
```

Inline:

```
$...$
```

Prefer semantic Markdown over raw HTML.

---

# Mathematics Style

Mathematics should be precise.

Notation should be consistent throughout the project.

Prefer:

- vector notation
- clearly defined symbols
- dimensional consistency

Whenever introducing a theorem:

1. intuition
2. formal definition
3. proof (if appropriate)
4. worked example
5. engineering interpretation

---

# Figures

Figures should

- have captions
- be referenced in text
- avoid unnecessary decoration

GeoGebra is frequently used for illustrations.

TikZ may be introduced later.

---

# Software Philosophy

Software included in the repository is educational.

Quality goals:

- modern C++
- clean architecture
- extensive comments only where valuable
- readable names
- minimal dependencies

Avoid over-engineering.

---

# Git Workflow

Work directly on `main` unless the maintainer explicitly requests a separate
branch.

Small commits.

Meaningful commit messages.

Main branch should remain stable.

Do not create branches without an explicit request from the maintainer.

---

# Coding Standards

Prefer

- C++20
- Python 3.13+
- CMake where appropriate

Follow existing project conventions.

Never reformat unrelated code.

Avoid unnecessary dependencies.

---

# Linux Environment

Primary development environment:

Arch Linux

Preferred package manager:

```
paru
```

Primary editor:

VS Code

Terminal:

Kitty

Shell:

bash

Window manager:

Hyprland

---

# Documentation Standards

Every major concept should eventually have

- introduction
- references
- examples
- diagrams
- exercises
- summary

Cross-reference related topics whenever appropriate.

---

# Current Academic Focus

Linear Algebra II

Topics completed or in progress include

- vectors
- linear combinations
- span
- linear dependence
- basis
- dot product
- cross product
- matrices
- systems of equations
- null space
- column space

Upcoming topics include

- eigenvalues
- eigenvectors
- orthogonality
- least squares
- QR factorization

---

# Long-Term Subjects

The repository is expected to expand into

- Calculus
- Differential Equations
- Classical Mechanics
- Aerospace Engineering
- Orbital Mechanics
- Control Theory
- Signal Processing
- GNSS
- VLBI
- Satellite Laser Ranging
- Space Systems
- Embedded Programming
- Scientific Computing
- Linux
- C++
- Python

---

# Website

Public material will eventually be published using

Hugo + PaperMod

Domain:

```
jonleithe.no
```

The website is intended to be minimal, fast, and text-oriented.

---

# Author Background

The project is maintained by Jon Leithe.

Professional background includes

- scientific infrastructure
- VLBI
- GNSS
- Hydrogen masers
- Linux systems
- automation
- Python
- C++
- electronics
- instrumentation

The project reflects both academic study and professional engineering experience.

---

# Project Goals

The long-term objective is to produce an engineering knowledge base comparable to a professionally maintained technical handbook.

The repository should remain useful for decades.

Every document should be something the author would confidently revisit years later.

---

# Guidance for AI Coding Agents

When modifying this repository:

- Preserve the educational focus.
- Do not simplify mathematics incorrectly.
- Prefer correctness over brevity.
- Avoid introducing unnecessary frameworks.
- Keep Markdown readable.
- Respect the existing repository organization.
- Produce explanations suitable for future students.
- When editing notes, maintain a consistent tone and notation across the repository.
- Suggest improvements, but avoid large unsolicited restructurings.
- Keep changes focused on the requested task unless broader refactoring is explicitly requested.

---

I would actually go one step further. Rather than a single brief, I'd recommend three companion documents at the root of the repository:

- **`AGENTS.md`** — instructions specifically for Codex/Claude/AI agents (coding style, conventions, workflow).
- **`PROJECT.md`** — the project's vision, goals, roadmap, and structure.
- **`AUTHOR.md`** — background about you, your development environment (Arch Linux, `paru`, Hyprland, Kitty, VS Code, etc.), and the rationale behind design decisions.

That separation makes it easier for both humans and AI agents to locate the right context, and it's the structure I would use for a long-lived project like Project Polaris.
