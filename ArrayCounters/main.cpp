#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main(int argc, char* argv[])
{
    int lenght{0};
    int maxValue{0};
    int inputValue{0};
    std::string input;

    std::cout << "Please, input the length of the arrays and the maximum value: ";
    std::getline(std::cin, input);

    std::stringstream stream(input);
    stream >> lenght >> maxValue;
    // std::cout << lenght << " " << maxValue << std::endl;

    std::vector<int> arrayToCount;
    std::vector<int> arrayCounter(++maxValue,0);

    std::cout << "Please, input the values for the array, separated by space (e.g. 1 2 3): ";
    for (auto i = 0; i < lenght; ++i)
    {
        std::cin >> inputValue;
        arrayToCount.push_back(inputValue);
        arrayCounter.at(inputValue)++;
    }

    for (auto i = 1; i < maxValue; ++i)
    {
        std::cout << arrayCounter[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}