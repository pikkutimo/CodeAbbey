#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <sstream>

std::string getAverage(std::string&);

int main(int argc, char *argv[])
{
    int numberOfCases{0};
    std::string inputArray;
    std::string temp;

    std::vector<std::string> arrays;

    std::cout << "Please, enter the number of test-cases:\n";
    std::getline(std::cin, temp);
    numberOfCases = std::stoi(temp);

    for (int i = 0; i < numberOfCases; i++)
    {
        std::getline(std::cin,inputArray);
        arrays.push_back(inputArray);
    }

    for (auto& singularArray: arrays)
    {
        std::cout << getAverage(singularArray) << " ";
    }

    std::cout << std::endl;

    return 0;
}

std::string getAverage(std::string& arrayToCalculate)
{
    int sum{0};
    int temp{0};
    int arraySize{0};
    std::stringstream s(arrayToCalculate);

    while(s>>temp)
    {
        if (temp == 0) break;
        sum += temp;
        arraySize++;
    }

    return std::to_string(static_cast<int>(std::round(1.0*sum/arraySize)));
}