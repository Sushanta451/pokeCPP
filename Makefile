# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17 -Wall
INCLUDES = -I/opt/homebrew/include
LIBS = -L/opt/homebrew/lib -lraylib

# Directories
SRC_DIR = src
BUILD_DIR = build

# Target executable
TARGET = pokemon

# Source files (will find all .cpp files in src/)
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Default target
all: $(TARGET)

# Link
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) $(LIBS) -o $(TARGET)

# Compile
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean build files
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Run the game
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
