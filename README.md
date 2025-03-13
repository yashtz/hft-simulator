# To build,

# Compile files
g++ -std=c++17 -Wall -Wextra -O2 -c Order.cpp -o Order.o
g++ -std=c++17 -Wall -Wextra -O2 -c OrderBook.cpp -o OrderBook.o
g++ -std=c++17 -Wall -Wextra -O2 -c MatchingEngine.cpp -o MatchingEngine.o
g++ -std=c++17 -Wall -Wextra -O2 -c main.cpp -o main.o

# Link and create the .exe
g++ -std=c++17 -Wall -Wextra -O2 Order.o OrderBook.o MatchingEngine.o main.o -o hft-simulator

# Run it
./hft-simulator
