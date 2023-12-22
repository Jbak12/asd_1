CXX = g++
CXXFLAGS = -std=c++11
TARGETS = BinaryTree.x
SRCS = BinaryTree.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGETS)

%.x: %.o
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGETS)

.PHONY: all run clean