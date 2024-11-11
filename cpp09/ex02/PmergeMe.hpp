
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
class VectorFJ {
private:
    void separateIntoGroups(const std::vector<int>& arr, 
                            std::vector<int>& winners, 
                            std::vector<int>& losers);
    size_t binarySearch(const std::vector<int>& sorted, int value);
    void insertLosers(std::vector<int>& winners, const std::vector<int>& losers);

public:
    VectorFJ();
    VectorFJ(const VectorFJ& other);
    VectorFJ& operator=(const VectorFJ& other);
    ~VectorFJ();
    std::vector<int> sort(std::vector<int>& arr);
    std::vector<int> parseInput(int argc, char **argv);
    void printVector(const std::vector<int>& vec);

};

class DequeFJ {
    private:
        void separateIntoGroups(const std::deque<int>& arr, 
                            std::deque<int>& winners, 
                            std::deque<int>& losers);
        size_t binarySearch(const std::deque<int>& sorted, int value);
        void insertLosers(std::deque<int>& winners, const std::deque<int>& losers);
        std::deque<size_t> generateJacobsthalNumbers(size_t n);

    public:
        DequeFJ();
        DequeFJ(const DequeFJ& other);
        DequeFJ& operator=(const DequeFJ& other);
        ~DequeFJ();
        std::deque<int> sort(std::deque<int>& arr);
        std::deque<int> parseInput(int argc, char **argv);
        void printDeque(const std::deque<int>& deq);
    };

#endif