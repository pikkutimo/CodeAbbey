#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <sstream>
#include <iterator>

constexpr int rows = 4;

std::string checkGuesses(std::vector<std::vector<int>>&, std::vector<std::pair<std::string, int>>&);

int main(int argc, char* argv[])
{
    std::vector<std::vector<int>> digits{ {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
                                          {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
                                          {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
                                          {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} };
    std::vector<std::pair<std::string, int>> partlyCorrect;
    int numberOfAnswers{0};
    int numberOfCorrectDigits{0};
    std::string input;

    std::getline(std::cin, input);
    numberOfAnswers = std::stoi(input);
    
    for (int i = 0; i < numberOfAnswers; ++i)
    {
        std::getline(std::cin, input);
        std::string guess = input.substr(0, 4);
        numberOfCorrectDigits = std::stoi(input.substr(5, 1));
        if (numberOfCorrectDigits == 0)
        {
            int i{0};
            int number = std::stoi(guess);
            if (guess[0] == '0')
            {
                digits[i].erase(std::remove(digits[i].begin(), digits[i].end(), 0), digits[i].end());
            }
            else
            {
                digits[i].erase(std::remove(digits[i].begin(), digits[i].end(), number/1000), digits[i].end());
            }
            ++i;
            number %= 1000;
            digits[i].erase(std::remove(digits[i].begin(), digits[i].end(), number/100), digits[i].end());
            ++i;
            number %= 100;
            digits[i].erase(std::remove(digits[i].begin(), digits[i].end(), number/10), digits[i].end());
            ++i;
            number %= 10;
            digits[i].erase(std::remove(digits[i].begin(), digits[i].end(), number), digits[i].end());
        }
        else
        {
            partlyCorrect.emplace_back(std::make_pair(guess, numberOfCorrectDigits));
        } 
    }

    std::cout << checkGuesses(digits, partlyCorrect) <<std::endl;

    
    return 0;
}

std::string checkGuesses(std::vector<std::vector<int>>& digits, std::vector<std::pair<std::string, int>>& guesses)
{   
    // for (auto row: digits)
    // {
    //     for (auto digit: row)
    //     {
    //         std::cout << digit;
    //     }
    //     std::cout << std::endl;
    // }

    std::string answer{"No"};
    std::vector<std::string> possibleCombinations;

    for (int i = 0; i < digits[0].size(); ++i)
    {
        for (int j = 0; j < digits[1].size(); ++j)
        {
            for (int k = 0; k < digits[2].size(); ++k)
            {
                for (int l = 0; l < digits[3].size(); ++l)
                {
                    int number = digits[0][i] * 1000 + digits[1][j] * 100 + digits[2][k] + digits[3][l];
                    possibleCombinations.emplace_back(std::to_string(number));
                }
            }
        }
    }

    for (auto combination: possibleCombinations)
    {
        int outerCounter{0};
        for (auto tuple: guesses)
        {
            int innerCounter{0};
            for (int i = 0; i < rows; ++i)
            {
                if (tuple.first[i] == combination   [i]) innerCounter++;
            }

            if (innerCounter == tuple.second) outerCounter++;
        }

        if (outerCounter == guesses.size())
        {
            answer = combination;
            break;
        }
    }

    return answer;
}
