#include <iostream>
#include <vector>
#include <utility>

int convertToDice(const std::pair<int, int>&);

int main(int argc, char *argv[])
{
    int distictPairs{0};
    int firstNumber{0};
    int secondNumber{0};

    std::vector<std::pair<int, int>> listOfPairs;

    std::cout << "How many pairs: ";
    std::cin >> distictPairs;

    std::cout << "Please, input the pairs separated by space (e.g. 12.3232 23.3121):" << std::endl;

    for (int i = 0; i < distictPairs; ++i)
    {
        std::cin >> firstNumber >> secondNumber;
        listOfPairs.emplace_back(std::make_pair(firstNumber, secondNumber));
    }

    for (auto& tuple: listOfPairs)
    {
       std::cout << convertToDice(tuple) << " ";
    }

    std::cout << std::endl;

    return 0;
}

int convertToDice(const std::pair<int, int>& tuple)
{
    constexpr int distinctValues{6};

    return (tuple.first%distinctValues + 1) + (tuple.second%distinctValues + 1);
}