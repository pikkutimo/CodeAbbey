#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>

void openFile(int&, std::vector<std::string>&);
std::string dealer(std::vector<std::string> *);

int main(int argc, char* argv[])
{
    int testCases{0};
    std::vector<std::string> tests;

    openFile(testCases, tests);

    std::cout << dealer(&tests) << std::endl;

    return 0;
}

void openFile(int& testCases, std::vector<std::string>& cases)
{
    std::string input;
    std::fstream file("data.txt");

    if (file.is_open())
    {
        std::getline(file, input);
        testCases = std::stoi(input);

        while(std::getline(file, input))
        {
            cases.emplace_back(input);
        }

        file.close();
    }
    else
    {
        std::cout << "Couldn't open the file." << std::endl;
    }
}

std::string dealer(std::vector<std::string> *players)
{
    std::string playerPoints{""};
    int sum{0};
    
    for (auto hand : *players)
    {
        std::cout << hand << std::endl;
        for (auto card : hand)
        {
            if (isdigit(card))
            {
                sum += card - 48;
            }
            else if (card == 'T' || card == 'J' || card == 'Q' || card == 'K')
            {
                sum += 10;
            }
            else if (card == 'A')
            {
                if (sum + 11 > 21)
                {
                    sum += 1;
                }
                else
                {
                    sum += 11;
                }
            }
        }

        if (sum <= 21)
        {
            playerPoints += std::to_string(sum);
        }
        else
        {
            playerPoints += "Bust";
        }
        
        playerPoints += " ";
        sum = 0;
    }
    return playerPoints;
}