# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude -g

# Directories
SRC_DIR = lib
TEST_DIR = test

# Collect all .cpp files from lib/
LIB_SRC = $(wildcard $(SRC_DIR)/*.cpp)
TEST_SRC = $(TEST_DIR)/main.cpp

# Executable name
TARGET = tuarg

# Default build rule
$(TARGET): $(LIB_SRC) $(TEST_SRC)
	$(CXX) $(CXXFLAGS) $(LIB_SRC) $(TEST_SRC) -o $(TARGET)

# Clean rule
clean:
	rm -f $(TARGET)