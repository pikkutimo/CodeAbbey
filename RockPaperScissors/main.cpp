#include <iostream>
#include <string>
#include <vector>

int whoWon(std::string&);
int main(int argc, char* argv[])
{
    int numberOfMatches{0};
    std::string input;
    std::vector<int> winners;

    std::getline(std::cin, input);
    numberOfMatches = std::stoi(input);

    for (int i = 0; i < numberOfMatches; ++i)
    {
        std::getline(std::cin, input);
        winners.emplace_back(whoWon(input));
    }

    for (auto winner: winners)
    {
        std::cout << winner << " ";
    }

    std::cout << std::endl;

    return 0;
}

int whoWon(std::string& battles)
{
    std::string lastMatch = battles.substr(battles.length() - 2);
    int winner{0};

    if (lastMatch == "PR" || lastMatch == "RS" || lastMatch == "SP") winner = 1;
    if (lastMatch == "PS" || lastMatch == "RP" || lastMatch == "SR") winner = 2;

    return winner;
}