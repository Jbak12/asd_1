CXX = g++
CXXFLAGS = -std=c++11
QUEUE_TARGET = Queue.x
GENERATOR_TARGET = generator.x
RADIX_TARGET = Radix.x  # Updated target name
SRCS = Queue.cpp
GENERATOR_SRCS = generator.cpp
RADIX_SRCS = Radix.cpp  # Updated source file name
OBJS = $(SRCS:.cpp=.o)
GENERATOR_OBJS = $(GENERATOR_SRCS:.cpp=.o)
RADIX_OBJS = $(RADIX_SRCS:.cpp=.o)  # Updated object file name

all: $(QUEUE_TARGET) $(GENERATOR_TARGET) $(RADIX_TARGET)  # Updated to include RADIX_TARGET

$(QUEUE_TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(QUEUE_TARGET) $(OBJS)

$(GENERATOR_TARGET): $(GENERATOR_OBJS)
	$(CXX) $(CXXFLAGS) -o $(GENERATOR_TARGET) $(GENERATOR_OBJS)

$(RADIX_TARGET): $(RADIX_OBJS)  # New target for Radix
	$(CXX) $(CXXFLAGS) -o $(RADIX_TARGET) $(RADIX_OBJS)  # Updated target name

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

run: $(QUEUE_TARGET)
	./$(QUEUE_TARGET)

generate: $(GENERATOR_TARGET)
	./$(GENERATOR_TARGET) | ./$(QUEUE_TARGET)

radix: $(RADIX_TARGET) 
	./$(RADIX_TARGET)  

clean:
	rm -f $(OBJS) $(GENERATOR_OBJS) $(RADIX_OBJS) $(QUEUE_TARGET) $(GENERATOR_TARGET) $(RADIX_TARGET)  # Updated to include RADIX_TARGET

.PHONY: all run generate radix clean
