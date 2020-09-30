#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <sstream>

int main(int argc, char* argv[])
{
    constexpr int numberOfLines{3};
    constexpr int valuesPerLine{100};
    constexpr int smallestDice{2};
    constexpr int largestDice{12};

    std::vector<std::vector<int>> lines;
    std::vector<int> singleLine;

    std::string input{""};
    std::string answer{""};
    int number{0};

    for (int i = 0; i < numberOfLines; ++i)
    {
        std::getline(std::cin, input);
        std::stringstream str(input);
        for (int j = 0; j < valuesPerLine; ++j)
        {
            str >> number;
            singleLine.emplace_back(number); 
        }
        lines.emplace_back(singleLine);
        singleLine.clear();
    }
    
    for (auto line: lines)
    {
        std::sort(line.begin(), line.end());
        std::cout << (double)(line[(valuesPerLine-1)/2] + line[valuesPerLine/2])/2.0 << std::endl; 
    }

    return 0;
}
