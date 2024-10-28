#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    // Test default constructor and size
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    // Test copy constructor and assignment operator
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        for (int i = 0; i < MAX_VAL; i++)
        {
            if (test[i] != numbers[i])
            {
                std::cerr << "Copy constructor failed" << std::endl;
                return 1;
            }
            if (test[i] != tmp[i])
            {
                std::cerr << "Assignment operator failed" << std::endl;
                return 1;
            }
        }
    }
    // Test negative index
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    // Test out of bounds
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}