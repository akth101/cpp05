
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T> {
    public:
        MutantStack();
        MutantStack(const MutantStack& other);
        MutantStack& operator=(const MutantStack& other);
        ~MutantStack();

        typedef typename std::deque<T>::iterator iterator;

        iterator begin();
        iterator end();

};

#include "MutantStack.tpp"

#endif