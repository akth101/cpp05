#include "PmergeMe.hpp"

/* VectorFJ */

VectorFJ::VectorFJ() {}

VectorFJ::VectorFJ(const VectorFJ& other) {
    (void)other;
}

VectorFJ& VectorFJ::operator=(const VectorFJ& other) {
    (void)other;
    return *this;
}

VectorFJ::~VectorFJ() {}

void VectorFJ::separateIntoGroups(const std::vector<int>& arr,
                                 std::vector<int>& winners, 
                                 std::vector<int>& losers) {
    for(size_t i = 0; i < arr.size() - 1; i += 2) {
        if(arr[i] > arr[i + 1]) {
            winners.push_back(arr[i]);
            losers.push_back(arr[i + 1]);
        } else {
            winners.push_back(arr[i + 1]);
            losers.push_back(arr[i]);
        }
    }
    // 홀수 개일 경우 마지막 요소 처리
    if (arr.size() % 2 != 0) {
        winners.push_back(arr.back());
    }
}

std::vector<int> VectorFJ::sort(std::vector<int>& arr) {
    if(arr.size() <= 1) 
        return arr;
    
    // 1. 큰 값과 작은 값으로 분리
    std::vector<int> winners;
    std::vector<int> losers;
    separateIntoGroups(arr, winners, losers);
        
    // 2. 승자들 재귀 정렬
    winners = sort(winners);
        
    // 3. 패자들 삽입
    insertLosers(winners, losers);
    
    return winners;
}

// 야콥스탈 수열 생성 함수 추가
std::vector<size_t> generateJacobsthalNumbers(size_t n) {
    std::vector<size_t> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    
    while (jacobsthal.back() < n) {
        size_t next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
        jacobsthal.push_back(next);
    }
    return jacobsthal;
}

// 이진 검색을 사용한 위치 찾기
size_t VectorFJ::binarySearch(const std::vector<int>& winners, int value) {
    return std::lower_bound(winners.begin(), winners.end(), value) - winners.begin();
}

// 메인 삽입 로직 수정
void VectorFJ::insertLosers(std::vector<int>& winners, const std::vector<int>& losers) {
    if (losers.empty())
        return;
    
    // 첫 번째 패자를 먼저 삽입
    size_t insertPosition = binarySearch(winners, losers[0]);
    winners.insert(winners.begin() + insertPosition, losers[0]);
    
    std::vector<size_t> jacobsthal = generateJacobsthalNumbers(losers.size());
    
    // 두 번째 패자부터 야콥스탈 수열에 따라 삽입
    for (size_t i = 1; i < jacobsthal.size(); ++i) {
        size_t currentJacobsthal = jacobsthal[i];
        size_t previousJacobsthal = jacobsthal[i - 1];
        
        // 현재 구간의 요소들을 역순으로 처리 (index가 2부터 시작하도록 수정)
        for (size_t index = currentJacobsthal; index > previousJacobsthal; --index) {
            if (index - 1 < losers.size() && index != 1) {  // index != 1 조건 추가
                int currentLoser = losers[index - 1];
                size_t insertPosition = binarySearch(winners, currentLoser);
                winners.insert(winners.begin() + insertPosition, currentLoser);
            }
        }
    }
}

std::vector<int> VectorFJ::parseInput(int argc, char **argv) {
    std::vector<int> numbers;
    for (int i = 1; i < argc; ++i) {
        if (std::atoi(argv[i]) < 0) {
            throw std::invalid_argument("Error: negative number provided");
        }
        numbers.push_back(std::atoi(argv[i]));
    }
    return numbers;
}

void VectorFJ::printVector(const std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

/* DequeFJ */

DequeFJ::DequeFJ() {}

DequeFJ::DequeFJ(const DequeFJ& other) {
    (void)other;
}

DequeFJ& DequeFJ::operator=(const DequeFJ& other) {
    (void)other;
    return *this;
}

DequeFJ::~DequeFJ() {}

std::deque<int> DequeFJ::parseInput(int argc, char **argv) {
    std::deque<int> numbers;
    for (int i = 1; i < argc; ++i) {
        if (std::atoi(argv[i]) < 0) {
            throw std::invalid_argument("Error: negative number provided");
        }
        numbers.push_back(std::atoi(argv[i]));
    }
    return numbers;
}

void DequeFJ::separateIntoGroups(const std::deque<int>& arr,
                                 std::deque<int>& winners,
                                 std::deque<int>& losers) {
    for (size_t i = 0; i < arr.size() - 1; i += 2) {
        if (arr[i] > arr[i + 1]) {
            winners.push_back(arr[i]);
            losers.push_back(arr[i + 1]);
        } else {
            winners.push_back(arr[i + 1]);
            losers.push_back(arr[i]);
        }
    }
    // 홀수 개일 경우 마지막 요소 처리
    if (arr.size() % 2 != 0) {
        winners.push_back(arr.back());
    }
}

std::deque<int> DequeFJ::sort(std::deque<int>& arr) {
    if(arr.size() <= 1)
        return arr;
    
    // 1. 큰 값과 작은 값으로 분리
    std::deque<int> winners;
    std::deque<int> losers;
    separateIntoGroups(arr, winners, losers);

    // 2. 승자들 재귀 정렬
    winners = sort(winners);
    
    // 3. 패자들 삽입
    insertLosers(winners, losers);

    return winners;
}

// 야콥스탈 수열 생성 함수 추가
std::deque<size_t> DequeFJ::generateJacobsthalNumbers(size_t n) {
    std::deque<size_t> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    
    while (jacobsthal.back() < n) {
        size_t next = jacobsthal.back() + 2 * jacobsthal[jacobsthal.size() - 2];
        jacobsthal.push_back(next);
    }
    return jacobsthal;
}

size_t DequeFJ::binarySearch(const std::deque<int>& sorted, int value) {
    return std::lower_bound(sorted.begin(), sorted.end(), value) - sorted.begin();
}

void DequeFJ::insertLosers(std::deque<int>& winners, const std::deque<int>& losers) {
    if (losers.empty())
        return;
    
    // 첫 번째 패자를 먼저 삽입
    size_t insertPosition = binarySearch(winners, losers[0]);
    winners.insert(winners.begin() + insertPosition, losers[0]);
    
    std::deque<size_t> jacobsthal = generateJacobsthalNumbers(losers.size());
    
    // 두 번째 패자부터 야콥스탈 수열에 따라 삽입
    for (size_t i = 1; i < jacobsthal.size(); ++i) {
        size_t currentJacobsthal = jacobsthal[i];
        size_t previousJacobsthal = jacobsthal[i - 1];
        
        // 현재 구간의 요소들을 역순으로 처리 (index가 2부터 시작)
        for (size_t index = currentJacobsthal; index > previousJacobsthal; --index) {
            if (index - 1 < losers.size() && index > 1) {  // index > 1 조건 추가
                int currentLoser = losers[index - 1];
                size_t insertPosition = binarySearch(winners, currentLoser);
                winners.insert(winners.begin() + insertPosition, currentLoser);
            }
        }
    }
}

void DequeFJ::printDeque(const std::deque<int>& deq) {
    for (size_t i = 0; i < deq.size(); ++i) {
        std::cout << deq[i] << " ";
    }
    std::cout << std::endl;
}

