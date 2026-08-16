QUARTO      := quarto
PYTHON      := python3

SOURCE_DIR  := notes
BUILD_DIR   := build
BOOK_CHAPTER_PROFILE := _quarto-auto-book.yml

SOURCES     := $(sort $(shell find $(SOURCE_DIR) -type f -name '*.md' -print))

.PHONY: all help note notes linear-algebra book site preview clean list

all: notes

help:
	@printf '%s\n' \
		'Project Polaris Academy build targets' \
		'' \
		'  make note NOTE=linear-algebra/courses/khan-academy/01-vectors-and-spaces.md' \
		'      Render one note as PDF with Quarto.' \
		'      NOTE may be relative to notes/, start with notes/, or be a unique filename.' \
		'' \
		'  make notes' \
		'      Render all notes discovered by _quarto-notes.yml as individual PDFs.' \
		'' \
		'  make linear-algebra' \
		'      Render the Khan linear algebra notes as one Quarto book PDF.' \
		'' \
		'  make book' \
		'      Discover personal notes and render the Quarto book PDF.' \
		'' \
		'  make site' \
		'      Render the home page and personal notes as a navigable HTML site.' \
		'' \
		'  make preview' \
		'      Render the personal-notes site and start a live preview.' \
		'' \
		'  make list' \
		'      List all Markdown note sources.' \
		'' \
		'  make clean' \
		'      Remove generated note PDFs and Quarto output.' \
		'' \
		'  make help' \
		'      Show this help.'

note:
	@if [ -z "$(NOTE)" ]; then \
		echo 'Error: NOTE is required.' >&2; \
		echo 'Example: make note NOTE=linear-algebra/courses/khan-academy/01-vectors-and-spaces.md' >&2; \
		exit 2; \
	fi
	@note='$(NOTE)'; \
	case "$$note" in \
		notes/*) ;; \
		*) \
			if [ -f "$(SOURCE_DIR)/$$note" ]; then \
				note="$(SOURCE_DIR)/$$note"; \
			else \
				matches="$$(find "$(SOURCE_DIR)" -type f -name "$${note##*/}" -print)"; \
				count="$$(printf '%s\n' "$$matches" | sed '/^$$/d' | wc -l)"; \
				if [ "$$count" -eq 1 ]; then \
					note="$$matches"; \
				elif [ "$$count" -gt 1 ]; then \
					echo "Error: NOTE '$${note##*/}' matches more than one file:" >&2; \
					printf '%s\n' "$$matches" >&2; \
					exit 2; \
				fi; \
			fi ;; \
	esac; \
	if [ ! -f "$$note" ]; then \
		echo "Error: note not found: $(NOTE)" >&2; \
		exit 2; \
	fi; \
	echo "Rendering $$note as PDF"; \
	$(QUARTO) render "$$note" --to pdf

notes:
	$(QUARTO) render --profile notes --to pdf

linear-algebra:
	$(QUARTO) render --profile linear-algebra --to pdf

book:
	$(PYTHON) scripts/generate-book-profile.py --output $(BOOK_CHAPTER_PROFILE)
	$(QUARTO) render --profile book,auto-book --to pdf

site:
	$(QUARTO) render --profile site --to html

preview:
	$(QUARTO) preview --profile site --to html --render html

list:
	@printf '%s\n' $(SOURCES)

clean:
	@if [ -d "$(BUILD_DIR)" ]; then \
		find "$(BUILD_DIR)" -type f -name '*.pdf' -delete; \
	fi
	@rm -rf "$(BUILD_DIR)/quarto" "$(BUILD_DIR)/site" "$(BUILD_DIR)/books"
	@rm -f "$(BOOK_CHAPTER_PROFILE)"
