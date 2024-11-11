
#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Usage: ./btc <input.txt>" << std::endl;
        return 1;
    }
    BitcoinExchange btc("data.csv");
    try {
        btc.parseData("data.csv");
        btc.handleInput(argv[1]);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
