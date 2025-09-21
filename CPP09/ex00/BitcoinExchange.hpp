#pragma once

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class BitcoinExchange
{
public:
    BitcoinExchange();
    BitcoinExchange(const std::string &data_file);
    ~BitcoinExchange(void);
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);

    double getBitcoinValue(int date, double amount) const;
    static int parseDate(const std::string &date_str);

private:
    std::map<int, double> priceData;
    void loadData(const std::string &data_file);
};