CXX = g++
CXXFLAGS = -std=c++11
LIST_TARGET = CursorList.x  
LIST_SRCS = CursorList.cpp 
LIST_OBJS = $(LIST_SRCS:.cpp=.o)  

LIST_ARR_TARGET = ArrayList.x  
LIST_ARR_SRCS = ArrayList.cpp 
LIST_ARR_OBJS = $(LIST_SRCS:.cpp=.o)  


all:  $(LIST_TARGET) $(LIST_ARR_TARGET)

$(LIST_TARGET): $(LIST_OBJS)
	$(CXX) $(CXXFLAGS) -o $(LIST_TARGET) $(LIST_OBJS) 

$(LIST_ARR_TARGET): $(LIST_ARR_OBJS)
	$(CXX) $(CXXFLAGS) -o $(LIST_ARR_TARGET) $(LIST_ARR_OBJS) 

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

run: $(LIST_TARGET)
	./$(LIST_TARGET)

clean:
	rm -f $(LIST_OBJS) $(LIST_TARGET) $(LIST_ARR_TARGET) $(LIST_ARR_OBJS)

.PHONY: all run generate clean  
