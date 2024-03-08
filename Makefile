# Compiler to use
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++11

# Name of the executable
TARGET = main

# List of source files
SRCS = main.cpp src/Node.cpp src/Station.cpp src/Pipe.cpp src/Reservoir.cpp src/NetworkManager.cpp src/Max_Flow.cpp src/City.cpp

# List of object files
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS) src/Max_Flow.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) src/Max_Flow.o

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)