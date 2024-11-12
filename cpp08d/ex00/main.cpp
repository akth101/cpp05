
#include "easyfind.hpp"

#include <vector>
#include <iostream>

int main() {
    std::vector<int> vec;   
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    // Test with a value that exists in the vector
    try {
        std::vector<int>::iterator iter = easyfind(vec, 3);
        std::cout << "Found: " << *iter << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    // Test with a value that does not exist in the vector
    try {
        std::vector<int>::iterator iter = easyfind(vec, 6);
        std::cout << "Found: " << *iter << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}