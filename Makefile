CC = clang
CPPFLAGS ?=
CFLAGS ?= -Wall -Wextra -std=c11
LDFLAGS ?=
LDLIBS ?=

DIST_DIR := dist
TARGET := $(DIST_DIR)/app
SOURCES := $(shell find . -type f -name '*.c' -not -path './$(DIST_DIR)/*' -not -path './.git/*' | sort)
HEADERS := $(shell find . -type f \( -name '*.h' -o -name '*.hh' -o -name '*.hpp' -o -name '*.hxx' \) -not -path './$(DIST_DIR)/*' -not -path './.git/*' | sort)
INCLUDE_DIRS := $(sort $(dir $(SOURCES) $(HEADERS)))

CPPFLAGS += -I. $(addprefix -I,$(INCLUDE_DIRS))

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	mkdir -p $(DIST_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $(SOURCES) $(LDLIBS) -o $@

clean:
	rm -rf $(DIST_DIR)