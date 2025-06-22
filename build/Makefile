# Makefile for ARM Assembly Prime Sorter
# Author: Om Tank

CC = aarch64-linux-gnu-gcc
ASM = aarch64-linux-gnu-as
LD = aarch64-linux-gnu-ld
OBJDUMP = aarch64-linux-gnu-objdump

CFLAGS = -Wall -Wextra -std=c99
ASMFLAGS = 
LDFLAGS = -static
DEBUGFLAGS = -g -O0
RELEASEFLAGS = -O2 -DNDEBUG

SRCDIR = src
BUILDDIR = build
TESTDIR = tests

SOURCES_C = $(SRCDIR)/main.c
SOURCES_ASM = $(SRCDIR)/isPrimeAssembly.s
TARGET = isPrime
TARGET_DEBUG = isPrime_debug

# Default target
all: $(TARGET)

# Release build
$(TARGET): $(SOURCES_C) $(SOURCES_ASM)
	$(CC) $(CFLAGS) $(RELEASEFLAGS) $(LDFLAGS) -o $@ $^

# Debug build  
debug: $(TARGET_DEBUG)
$(TARGET_DEBUG): $(SOURCES_C) $(SOURCES_ASM)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) $(LDFLAGS) -o $@ $^

# Generate assembly listing
listing: $(SOURCES_ASM)
	$(OBJDUMP) -d $(TARGET) > $(TARGET).listing

# Run tests
test: $(TARGET)
	@echo "Running basic functionality test..."
	./$(TARGET)

# Clean build artifacts
clean:
	rm -f $(TARGET) $(TARGET_DEBUG) *.listing *.o

# Install cross-compilation tools (Ubuntu/Debian)
install-tools:
	sudo apt-get update
	sudo apt-get install gcc-aarch64-linux-gnu
	sudo apt-get install qemu-user-static

# Help target
help:
	@echo "Available targets:"
	@echo "  all          - Build release version"
	@echo "  debug        - Build debug version"
	@echo "  test         - Run basic tests"
	@echo "  listing      - Generate assembly listing"
	@echo "  clean        - Remove build artifacts"
	@echo "  install-tools- Install ARM cross-compilation tools"

.PHONY: all debug test clean install-tools help
