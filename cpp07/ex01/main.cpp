
#include "iter.hpp"

int main(void) {
    int array[5] = {1, 2, 3, 4, 5};
    iter(array, 5, addSelf);
    iter(array, 5, print);
    std::cout << std::endl;
    std::string array2[5] = {"Hello", "World", "This", "Is", "Template"};
    iter(array2, 5, print);
    return 0;
}
