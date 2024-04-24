# Compiler and linker configurations
CXX := g++
CXXFLAGS := -Wall -Iinclude
LDFLAGS := 

# Directories
SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin
INCLUDE_DIR := include

# Files
SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))
EXECUTABLE := $(BIN_DIR)/CarMDP

# Default target
all: $(EXECUTABLE)

# Executable linking
$(EXECUTABLE): $(OBJECTS) | $(BIN_DIR)
	$(CXX) $(LDFLAGS) -o $@ $^

# Object compilation
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create binary directory
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean up
clean:
	rm -rf $(BIN_DIR) $(BUILD_DIR)

.PHONY: all clean
