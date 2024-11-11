
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange
{
    private:
        std::map<std::string, float> _data;
    public:
        BitcoinExchange(const std::string &filename);
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();
        std::map<std::string, float> getData() const;
        void parseData(const std::string &filename);
        bool isValidData(const std::string &date, float value, const std::string &kind);
        bool isNumeric(const std::string &str);
        void handleInput(const std::string &filename);
        float stringToFloat(const std::string& str);

};

#endif
