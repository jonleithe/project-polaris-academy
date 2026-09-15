# Book Build Handoff — 2026-09-15

## Current State

- Austfonna is on `main` at commit `8b09253` and is up to date with `origin/main`.
- `make book` builds the PDF successfully at
  `build/books/academy/project-polaris-notes.pdf`.
- The final `make book` exit status on austfonna is caused only by
  `copy-book-to-jotta` being unable to write to the Jotta destination from the
  Codex sandbox. The PDF has already been created.

## Pull Request Branch

The branch `agent/add-project-context-and-update-notes` points to `1d11a24`.
It is an ancestor of `main`, so it has no commits that are absent from `main`.
Its tracked `Makefile` is consequently old and still invokes direct Pandoc with
`pandoc-crossref`; current `main` uses the Quarto build instead.

Do not delete or close the pull request before checking isachsenfonna for
uncommitted image work.

## Continue on Isachsenfonna

First inspect the PR branch for uncommitted image edits:

```bash
git switch agent/add-project-context-and-update-notes
git status --short
git diff -- images
```

If image changes are present, preserve them and update the PR branch before
pushing it:

```bash
git add images
git commit -m "docs: refine book images"
git fetch origin
git rebase origin/main
make book
git push --force-with-lease
```

If there are no uncommitted image changes, switch to and update `main` instead:

```bash
git switch main
git pull --ff-only
make book
```

## Follow-up Improvement

Consider separating `copy-book-to-jotta` into a target such as `make sync-book`
so that `make book` remains portable and only reports the status of the PDF
build itself.
