
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container, int value) {
    typename T::iterator iter = std::find(container.begin(), container.end(), value);
    if (iter == container.end())
        throw std::runtime_error("Error: The value is not in this container");
    return iter;
}

#endif