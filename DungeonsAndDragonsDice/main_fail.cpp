#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <sstream>

std::string searchForDice(const float&);

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
        auto minimum = std::min_element(line.begin(), line.end());
        auto maximum = std::max_element(line.begin(), line.end());
        int sum{0};
        for (auto num: line)
        {
            sum += num;   
        }
        float average = 1.0 * sum / 100;
        std::cout << "The minimum: " << *minimum << " maximum: " << *maximum << " Mean: " << 1.0*sum/100 << std::endl;
        

        std::string verdict{""};

        if (*minimum == 1)
        {
            for (int i = 2; i <=12; ++i)
            {
                if (i >= *maximum)
                {
                    verdict = "1d" + std::to_string(i) + " ";
                }
            }
        }
        else
        {
            verdict = searchForDice(average);
        }

        answer += verdict;

    }

    std::cout << answer << std::endl;

    return 0;
}

std::string searchForDice(const float& average)
{
    std::string verdict{""};
    float difference{0};
    float minDifference{1000.0};
    
    for (int dice = 2; dice < 6; ++dice)
    {
        for (int diceEyes = 2; diceEyes < 14; diceEyes += 2)
        {
            float rollAverage = 1.0 * dice * (diceEyes/2);
            difference = std::abs(average - rollAverage);
            if (difference < minDifference)
            {
                minDifference = difference;
                verdict = std::to_string(dice) + "d" + std::to_string(diceEyes) + " ";
            }
        }
    }
    
    
    
    return verdict;
}
