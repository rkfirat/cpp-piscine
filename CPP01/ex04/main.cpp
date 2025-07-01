#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main(int argc, char const *argv[])
{
    if (argc != 4)
    {
        std::cerr << "\033[1;31m❌ Usage:\033[0m ./des <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty())
    {
        std::cerr << "\033[1;31m❌ Error:\033[0m s1 cannot be empty" << std::endl;
        return 1;
    }

    std::ifstream infile(filename.c_str());
    if (!infile.is_open())
    {
        std::cerr << "\033[1;31m❌ Error:\033[0m could not open file '" << filename << "'" << std::endl;
        return 1;
    }

    std::ostringstream buffer;
    buffer << infile.rdbuf();
    std::string content = buffer.str();
    infile.close();

    std::size_t pos = 0;
    while ((pos = content.find(s1, pos)) != std::string::npos)
    {
        content.erase(pos, s1.length());
        content.insert(pos, s2);
        pos += s2.length();
    }

    std::string outname = filename + ".replace";
    std::ofstream outfile(outname.c_str());
    if (!outfile.is_open())
    {
        std::cerr << "\033[1;31m❌ Error:\033[0m could not create file '" << outname << "'" << std::endl;
        return 1;
    }

    outfile << content;
    outfile.close();

    std::cout << "\033[1;32m✅ Replacements saved to:\033[0m " << outname << std::endl;

    return 0;
}
