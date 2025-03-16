# Compiler
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Executable
TARGET = dijkstra

# Source Files
SRC = main.cpp dijkstra.cpp
OBJ = $(SRC:.cpp=.o)
HEADERS = dijkstra.h

# Build Executable
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Compile C++ files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean Build Files
clean:
	rm -f $(OBJ) $(TARGET)

# Run Program
run: $(TARGET)
	./$(TARGET)
