
#include "Span.hpp"
#include <iostream>

int main() {
    Span sp = Span(20);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    //normal operation
    std::cout << "normal operation" << std::endl;
    try {
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    //test addRange
    std::cout << "test addRange" << std::endl;
    try {
        sp.addRange(10, 5);
        std::vector<int> vec = sp.getVec();
        for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    //exception operation
    std::cout << "exception operation" << std::endl;
    try {
        Span sp2 = Span(1);
        std::cout << sp2.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}
