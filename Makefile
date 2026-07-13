PANDOC      := pandoc

SOURCE_DIR  := notes
BUILD_DIR   := build
PANDOC_DIR  := pandoc
DEFAULTS    := $(PANDOC_DIR)/defaults.yaml
STYLE       := $(PANDOC_DIR)/polaris.tex
BOOK_METADATA := $(PANDOC_DIR)/book.yaml
BOOK_STYLE  := $(PANDOC_DIR)/book-title.tex
BOOK_IMAGES := $(sort $(wildcard images/book-cover-*.png))

SOURCES     := $(sort $(shell find $(SOURCE_DIR) -type f -name '*.md' -print))
PDFS        := $(patsubst $(SOURCE_DIR)/%.md,$(BUILD_DIR)/%.pdf,$(SOURCES))
RESOURCE_PATH := .:$(SOURCE_DIR):images:$(shell find $(SOURCE_DIR) -type d -print | paste -sd:)

PANDOC_FLAGS := --defaults=$(DEFAULTS) --resource-path=$(RESOURCE_PATH)

.PHONY: all book clean list

all: $(PDFS)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.pdf: $(SOURCE_DIR)/%.md $(DEFAULTS) $(STYLE)
	mkdir -p $(@D)
	$(PANDOC) $< $(PANDOC_FLAGS) -o $@

book: $(SOURCES) $(DEFAULTS) $(STYLE) $(BOOK_METADATA) $(BOOK_STYLE) $(BOOK_IMAGES) | $(BUILD_DIR)
	$(PANDOC) $(SOURCES) $(PANDOC_FLAGS) \
		--defaults=$(BOOK_METADATA) \
		--include-in-header=$(BOOK_STYLE) \
		-o $(BUILD_DIR)/project-polaris-notes.pdf

list:
	@printf '%s\n' $(SOURCES)

clean:
	@if [ -d "$(BUILD_DIR)" ]; then \
		find "$(BUILD_DIR)" -type f -name '*.pdf' -delete; \
	fi
