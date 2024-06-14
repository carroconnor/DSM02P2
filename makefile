# Compiler and compiler flags
CXX = g++
CXXFLAGS = -pedantic-errors -fdiagnostics-color=always -g

# Target executable
TARGET = main

# Source files
SRCS = main.cpp person.cpp

# Header files
HDRS = orderedLinkedList.h linkedList.h linkedListIterator.h person.h

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default rule
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files
%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $<

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET)
