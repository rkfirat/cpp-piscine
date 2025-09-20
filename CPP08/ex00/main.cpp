#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stdexcept>
#include "easyfind.hpp"

int main()
{
    std::cout << "--- easyfind Fonksiyonu Test Ediliyor ---" << std::endl;
    std::cout << "------------------------------------------" << std::endl;

    std::cout << "--- Vektorde Eleman Bulma ---" << std::endl;
    std::vector<int> numbers_vec;
    numbers_vec.push_back(10);
    numbers_vec.push_back(20);
    numbers_vec.push_back(30);
    numbers_vec.push_back(40);
    numbers_vec.push_back(50);
    int value_to_find_success = 30;

    try
    {
        std::vector<int>::iterator it = easyfind(numbers_vec, value_to_find_success);
        std::cout << "Aranan deger " << value_to_find_success << " bulundu. Deger: " << *it << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Hata yakalandi: " << e.what() << std::endl;
    }

    std::cout << "\n------------------------------------------" << std::endl;

    std::cout << "--- Listede Olmayan Eleman Aramasi ---" << std::endl;
    std::list<int> numbers_list;
    numbers_list.push_back(1);
    numbers_list.push_back(2);
    numbers_list.push_back(3);
    numbers_list.push_back(4);
    numbers_list.push_back(5);
    int value_to_find_fail = 100;

    try
    {
        std::list<int>::iterator it = easyfind(numbers_list, value_to_find_fail);
        std::cout << "Aranan deger bulundu: " << *it << std::endl;
    }
    catch (const std::runtime_error& e)
    {
        std::cout << "Basariyla hata yakalandi: " << e.what() << std::endl;
    }

    std::cout << "\n------------------------------------------" << std::endl;

    std::cout << "--- Deque'de Eleman Bulma ---" << std::endl;
    std::deque<int> numbers_deque;
    numbers_deque.push_back(5);
    numbers_deque.push_back(15);
    numbers_deque.push_back(25);
    numbers_deque.push_back(35);
    numbers_deque.push_back(45);
    int value_to_find_another = 25;

    try {
        std::deque<int>::iterator it = easyfind(numbers_deque, value_to_find_another);
        std::cout << "Aranan deger " << value_to_find_another << " bulundu. Deger: " << *it << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Hata yakalandi: " << e.what() << std::endl;
    }

    std::cout << "\n--- Testler Tamamlandi ---" << std::endl;

    return 0;
}