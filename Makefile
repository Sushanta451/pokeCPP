# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17 -Wall
INCLUDES = -I/opt/homebrew/include -Isrc
LIBS = -L/opt/homebrew/lib -lraylib

# Target executable
TARGET = pokemon

# Find all .cpp files recursively (including subdirectories!)
SOURCES = $(shell find src -name "*.cpp")
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(TARGET)

# Link
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) $(LIBS) -o $(TARGET)

# Compile
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Clean
clean:
	rm -f $(shell find src -name "*.o") $(TARGET)

# Run
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run