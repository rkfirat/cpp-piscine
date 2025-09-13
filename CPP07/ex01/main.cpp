#include "iter.hpp"
#include <iostream>

template <typename T>
void printElement(const T& element)
{
    std::cout << element << " ";
}

void increment(int& n)
{
    n++;
}

void addSuffix(std::string& s)
{
    s += "_alo";
}

int main(void)
{
    std::cout << "--- Integer Dizisi Testi ---" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    int intArrayLength = 5;

    std::cout << "Orijinal Dizi: ";
    iter(intArray, intArrayLength, printElement<int>);
    std::cout << std::endl;

    std::cout << "Dizi elemanları artırılıyor..." << std::endl;
    iter(intArray, intArrayLength, increment);

    std::cout << "Değiştirilmiş Dizi: ";
    iter(intArray, intArrayLength, printElement<int>);
    std::cout << std::endl << std::endl;


    std::cout << "--- String Dizisi Testi ---" << std::endl;
    std::string stringArray[] = {"Merhaba", "Dunya", "C++"};
    int stringArrayLength = 3;

    std::cout << "Orijinal Dizi: ";
    iter(stringArray, stringArrayLength, printElement<std::string>);
    std::cout << std::endl;

    std::cout << "Dizi elemanları değiştiriliyor..." << std::endl;
    iter(stringArray, stringArrayLength, addSuffix);

    std::cout << "Değiştirilmiş Dizi: ";
    iter(stringArray, stringArrayLength, printElement<std::string>);
    std::cout << std::endl << std::endl;


    std::cout << "--- const float Dizisi Testi ---" << std::endl;
    const float floatArray[] = {1.1f, 2.2f, 3.3f};
    int floatArrayLength = 3;

    std::cout << "const Dizi: ";
    iter(floatArray, floatArrayLength, printElement<float>);
    std::cout << std::endl;

    return 0;
}