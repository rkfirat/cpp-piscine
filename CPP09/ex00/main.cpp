#include "BitcoinExchange.hpp"

int main(int argc, char const *argv[])
{
    try
    {
        if (argc != 2)
        {
            throw std::runtime_error("Could not open input file.");
            return 1;
        }
        BitcoinExchange btc("data.csv");
        std::ifstream input(argv[1]);
        if (!input.is_open())
        {
            throw std::runtime_error("Could not open input file.");
        }
        std::string line;
        std::getline(input, line);
        while (std::getline(input, line))
        {
            size_t pipe_position = line.find(" | ");
            if (pipe_position == std::string::npos)
            {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }

            std::string dateStr = line.substr(0, pipe_position);
            std::string priceStr = line.substr(pipe_position + 3);
            int day = BitcoinExchange::parseDate(dateStr);
            std::stringstream ss(priceStr);
            double value;
            ss >> value;

            if (ss.fail() || !ss.eof())
            {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }

            if (value < 0)
            {
                std::cerr << "Error: not a positive number." << std::endl;
                continue;
            }

            if (value > 1000)
            {
                std::cerr << "Error: too large a number." << std::endl;
                continue;
            }
            double totalValue = btc.getBitcoinValue(day, value);
            std::cout << dateStr << " => " << value << " = " << totalValue << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
