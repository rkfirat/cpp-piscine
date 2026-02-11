#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string &data_file)
{
    loadData(data_file);
    if (this->priceData.empty())
    {
        throw std::runtime_error("Error: Bitcoin data could not be loaded or is empty.");
    }
}
BitcoinExchange::~BitcoinExchange(void)
{
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    this->priceData = other.priceData;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        this->priceData = other.priceData;
    }
    return *this;
}

double BitcoinExchange::getBitcoinValue(int date, double amount) const
{
    std::map<int, double>::const_iterator it = priceData.find(date);

    if (it == priceData.end())
    {
        it = priceData.lower_bound(date);
        if (it == priceData.begin())
        {
            throw std::runtime_error("Date is out of data range.");
        }
        --it;
    }
    return amount * it->second;
}

int BitcoinExchange::parseDate(const std::string &date_str)
{
    struct tm tm_struct = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    if (strptime(date_str.c_str(), "%Y-%m-%d", &tm_struct) == NULL)
    {
        throw std::invalid_argument("Error: bad input date format => " + date_str);
    }

    time_t seconds = mktime(&tm_struct);

    if (seconds == -1)
    {
        throw std::invalid_argument("bad input => " + date_str);
    }

    seconds /= 86400;

    return (static_cast<int>(seconds));
}

void BitcoinExchange::loadData(const std::string &data_file)
{
    std::ifstream file(data_file.c_str());
    if (!file.is_open())
    {
        throw std::runtime_error("could not open data file.");
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        size_t comma_position = line.find(',');
        if (comma_position == std::string::npos)
        {
            std::cerr << "Warning: Invalid line skipped (no comma) => " << line << std::endl;
            continue;
        }
        try
        {
            std::string dateStr = line.substr(0, comma_position);
            std::string priceStr = line.substr(comma_position + 1);
            int day = parseDate(dateStr);
            std::stringstream ss(priceStr);
            double price;
            ss >> price;

            if (!ss.eof() || price < 0.0f || ss.fail())
            {
                std::cerr << "Warning: Invalid price value, skipping line => " << line << std::endl;
                continue;
            }
            priceData[day] = price;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}