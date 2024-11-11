
#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

BitcoinExchange::BitcoinExchange(const std::string &filename) {
    parseData(filename);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other)
        _data = other._data;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::parseData(const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::string date = line.substr(0, line.find(','));
        float value = stringToFloat(line.substr(line.find(',') + 1));
        if (!isValidData(date, value, "data"))
            break;
        _data[date] = value;
    }
}

bool BitcoinExchange::isNumeric(const std::string& str) {
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (!isdigit(*it)) {
            return false;
        }
    }
    return !str.empty();
}

bool BitcoinExchange::isValidData(const std::string &date, float value, const std::string &kind) {

    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);

    if (year.empty() || month.empty() || day.empty()) {
        std::cerr << "Error: invalid date format. date: " << date << std::endl;
        return false;
    }
    if (year.size() != 4 || month.size() != 2 || day.size() != 2) {
        std::cerr << "Error: invalid date format. date: " << date << std::endl;
        return false;
    }
    if (date[4] != '-' || date[7] != '-') {
        std::cerr << "Error: invalid date format. date: " << date << std::endl;
        return false;
    }
    if (!isNumeric(year) || !isNumeric(month) || !isNumeric(day)) {
        std::cerr << "Error: invalid date format. date: " << date << std::endl;
        return false;
    }
    if (month > "12" || month < "01") {
        std::cerr << "Error: month is out of range." << std::endl;
        return false;
    }
    if (day > "31" || day < "01") {
        std::cerr << "Error: day is out of range." << std::endl;
        return false;
    }
    if (value < 0) {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    if (kind == "input" && (value > 1000)) {
        std::cerr << "Error: too large number." << std::endl;
        return false;
    }
    return true;
}

void BitcoinExchange::handleInput(const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::string date = line.substr(0, line.find('|'));
        float value = stringToFloat(line.substr(line.find('|') + 2));
        if (!isValidData(date, value, "input"))
            continue;
        std::map<std::string, float>::const_iterator it = _data.lower_bound(date);
        if (it->first != date)
            --it;
        std::cout << date << " => " << value << " = " << it->second * value << std::endl;
    }
}

float BitcoinExchange::stringToFloat(const std::string& str) {
    std::istringstream iss(str);
    float result;
    if (!(iss >> result)) {
        throw std::invalid_argument("Error: cannot convert string to float. str: " + str);
    }
    return result;
}
