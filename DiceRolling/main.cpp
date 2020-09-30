#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
    int numberOfValues{0};
    double input{0};
    constexpr int distictNumbers{6};
    std::vector<double> listOfValues;

    std::cin >> numberOfValues;

    for (int i = 0; i < numberOfValues; ++i)
    {
        std::cin >> input;
        listOfValues.emplace_back(input); 
    }

    for (auto value: listOfValues)
    {
        std::cout << static_cast<int>(value*distictNumbers) + 1 << " ";
    }

    std::cout << std::endl;

    return 0;
}