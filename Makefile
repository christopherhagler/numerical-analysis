# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -O2 -std=c11
LDFLAGS = -lm -lcmocka  # Link math library and CMocka

# Directories
BUILD_DIR = build
SRC_DIR = src
TEST_DIR = test
INCLUDE_DIR = include

# Target executable
TARGET = $(BUILD_DIR)/test_bisection

# Source files
SRCS = $(SRC_DIR)/root_finding.c $(TEST_DIR)/test_bisection.c

# Object files (place in the build directory)
OBJS = $(patsubst %.c, $(BUILD_DIR)/%.o, $(SRCS))

# Default target: build the executable
all: $(TARGET)

# Rule to build the target
$(TARGET): $(OBJS)
	@echo "Linking target: $@"
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)

# Rule to compile source files into object files
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)  # Create the necessary subdirectory for the object file
	@echo "Compiling $< into $@"
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	@echo "Cleaning build directory..."
	rm -rf $(BUILD_DIR)

# Phony targets
.PHONY: all clean
