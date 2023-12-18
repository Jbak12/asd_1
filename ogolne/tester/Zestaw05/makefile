CXX = g++
CXXFLAGS = -std=c++11
TARGETS = BubbleSort.x InsertionSort.x SelectionSort.x CountingSort.x Generator.x
SRCS = BubbleSort.cpp InsertionSort.cpp SelectionSort.cpp CountingSort.cpp Generator.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGETS)

%.x: %.o
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# run: CursorList.x
# 	./CursorList.x

clean:
	rm -f $(OBJS) $(TARGETS)

.PHONY: all run clean