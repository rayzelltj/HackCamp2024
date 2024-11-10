# Compiler and flags
CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17

# Target executable
TARGET := HackCamp2024

# Source files
SRCS := main.cpp symptoms.cpp
HEADERS := symptoms.h

# Default rule
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $@ $(SRCS)

clean:
	rm -f $(TARGET)

.PHONY: all clean