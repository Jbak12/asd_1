CXX = g++
CXXFLAGS = -std=c++11
TARGETS = CursorList.x ArrayList.x
SRCS = CursorList.cpp ArrayList.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGETS)

%.x: %.o
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

run: CursorList.x
	./CursorList.x

clean:
	rm -f $(OBJS) $(TARGETS)

.PHONY: all run clean