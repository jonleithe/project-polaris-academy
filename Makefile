QUARTO      := quarto

SOURCE_DIR  := notes
BUILD_DIR   := build

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
		'      Render all notes configured in _quarto.yml as individual PDFs.' \
		'' \
		'  make linear-algebra' \
		'      Render the Khan linear algebra notes as one Quarto book PDF.' \
		'' \
		'  make book' \
		'      Render all notes as the complete Quarto book PDF.' \
		'' \
		'  make site' \
		'      Render the navigable HTML site in build/site/.' \
		'' \
		'  make preview' \
		'      Render all configured HTML documents and start a live preview.' \
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
	$(QUARTO) render --to pdf

linear-algebra:
	$(QUARTO) render --profile linear-algebra --to pdf

book:
	$(QUARTO) render --profile book --to pdf

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
