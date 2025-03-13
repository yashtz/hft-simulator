CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

SRCS = Order.cpp OrderBook.cpp MatchingEngine.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = hft_simulator

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)