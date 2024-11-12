
#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span {
    private:
        unsigned int _N;
        std::vector<int> _vec;
    public:
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();
        void addNumber(int number);
        int shortestSpan() const;
        int longestSpan() const;
        void addRange(int N, unsigned int cnt);
        std::vector<int> getVec() const;
        unsigned int getN() const;
};

#endif