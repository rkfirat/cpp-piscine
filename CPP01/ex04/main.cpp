#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


int main(int argc, char const *argv[])
{
    if (argc != 4)
    {
        std::cerr << "Usage: ./des <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty())
    {
        std::cerr << "s1 cannot be empty" << std::endl;
        return 1;
    }
    std::ifstream infile(filename.c_str());
    if (!infile.is_open())
    {
        std::cerr << "Error opening file " << filename << std::endl;
        return 1;
    }

    std::ostringstream buffer;
    buffer << infile.rdbuf();
    std::string content = buffer.str();
    infile.close();

    std::size_t pos = 0;
    while (true)
    {
        pos = content.find(s1, pos);
        if (pos == std::string::npos)
            break;
        content.erase(pos, s1.length());
        content.insert(pos, s2);
        pos += s2.length();
    }

    std::ofstream outfile((filename + ".replace").c_str());
    if (!outfile.is_open())
    {
        std::cerr << "Error creating file " << filename << ".replace" << std::endl;
        return 1;
    }

    outfile << content;
    outfile.close();

    return 0;
}
