#include "PmergeMe.hpp"

std::vector<int> merge(std::vector<int> left, std::vector<int> right)
{
    std::vector<int> result;

    while (left.size() > 0 && right.size() > 0)
    {
        if (left.at(0) < right.at(0))
        {
            result.push_back(left[0]);
            left.erase(left.begin());
        }
        else
        {
            result.push_back(right[0]);
            right.erase(right.begin());
        }
    }
    while (left.size() > 0)
    {
        result.push_back(left[0]);
        left.erase(left.begin());
    }
    while (right.size() > 0)
    {
        result.push_back(right[0]);
        right.erase(right.begin());
    }
    return result;
}

std::vector<int> merge_sort(std::vector<int> list)
{
    if (list.size() <= 1)
    {
        return list;
    }

    std::vector<int> left_split = std::vector<int>(list.begin(), list.begin() + list.size() / 2);
    std::vector<int> right_split = std::vector<int>(list.begin() + list.size() / 2, list.end());

    std::vector<int> left_sorted = merge_sort(left_split);
    std::vector<int> right_sorted = merge_sort(right_split);

    return merge(left_sorted, right_sorted);
}

int main(int argc, char const *argv[])
{
    if (argc == 1)
    {
        std::cout << "Usage: ./PmergeMe <numbers>" << std::endl;
        return 0;
    }
    std::vector<int> args;
    int i = 1;
    while (i < argc)
    {
        std::stringstream ss(argv[i]);
        int temp;
        ss >> temp;
        args.push_back(temp);
        i++;
    }
    std::cout << "Before:\t";
    for (size_t i = 0; i < args.size(); i++)
    {
        std::cout << args.at(i) << " ";
    }
    std::cout << std::endl
              << "After:\t";
    std::vector<int> result = merge_sort(args);
    for (size_t i = 0; i < result.size(); i++)
    {
        std::cout << result.at(i) << " ";
    }
    std::cout << std::endl;
    return 0;
}
