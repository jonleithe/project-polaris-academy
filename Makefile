PANDOC      := pandoc

SOURCE_DIR  := notes
BUILD_DIR   := build
PANDOC_DIR  := pandoc
DEFAULTS    := $(PANDOC_DIR)/defaults.yaml
STYLE       := $(PANDOC_DIR)/polaris.tex

SOURCES     := $(sort $(wildcard $(SOURCE_DIR)/*.md))
PDFS        := $(patsubst $(SOURCE_DIR)/%.md,$(BUILD_DIR)/%.pdf,$(SOURCES))

PANDOC_FLAGS := --defaults=$(DEFAULTS)

.PHONY: all book clean list

all: $(PDFS)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.pdf: $(SOURCE_DIR)/%.md $(DEFAULTS) $(STYLE) | $(BUILD_DIR)
	$(PANDOC) $< $(PANDOC_FLAGS) -o $@

book: $(SOURCES) $(DEFAULTS) $(STYLE) | $(BUILD_DIR)
	$(PANDOC) $(SOURCES) $(PANDOC_FLAGS) \
		-M title="Project Polaris Academy Notes" \
		-M subtitle="Personal engineering knowledge base" \
		-M author="Jon" \
		-M date="2026" \
		-o $(BUILD_DIR)/project-polaris-notes.pdf

list:
	@printf '%s\n' $(SOURCES)

clean:
	rm -rf $(BUILD_DIR)
