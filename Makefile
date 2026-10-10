CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
TARGET   = queue

SRCS = Очередь.cpp основной.cpp
OBJS = $(SRCS:.cpp=.o)
HDRS = Очередь.h

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all run clean
