CXX = g++
CXXFLAGS = -std=c++17
TARGETS = Dict.x
SRCS = Dict.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGETS)

%.x: %.o
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<


clean:
	rm -f $(OBJS) $(TARGETS)

.PHONY: all run clean