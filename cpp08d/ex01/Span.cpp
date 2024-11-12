
#include "Span.hpp"
#include <algorithm>

Span::Span(unsigned int N) : _N(N) {
    _vec.reserve(N);
}

Span::Span(const Span& other) : _N(other._N), _vec(other._vec) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _N = other._N;
        _vec = other._vec;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (_vec.size() >= _N)
        throw std::runtime_error("Error: The container is full");
    _vec.push_back(number);
}

int Span::shortestSpan() const {
    if (_vec.size() < 2)
        throw std::runtime_error("Error: There is no span to find");
    int min_span = 2147483647;
    for (size_t i = 0; i < _vec.size() - 1; ++i) {
        for (size_t j = i + 1; j < _vec.size(); ++j) {
            if (abs(_vec[j] - _vec[i]) < min_span)
                min_span = abs(_vec[j] - _vec[i]);
        }
    }
    return min_span;
}

int Span::longestSpan() const {
    if (_vec.size() < 2)
        throw std::runtime_error("Error: There is no span to find");
    return *std::max_element(_vec.begin(), _vec.end()) - *std::min_element(_vec.begin(), _vec.end());
}

void Span::addRange(int N, unsigned int cnt) {
    if (N + _vec.size() > _N)
        throw std::runtime_error("Error: The container is full");
    _vec.insert(_vec.end(), N, cnt);
}

std::vector<int> Span::getVec() const {
    return _vec;
}

unsigned int Span::getN() const {
    return _N;
}