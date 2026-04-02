CXX = g++
CXXFLAGS = -Wall -std=c++11
TARGET = programa
SRCS = $(wildcard *.cpp)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)
