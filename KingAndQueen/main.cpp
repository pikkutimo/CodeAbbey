#include <iostream>
#include <string>
#include <cmath>


int main(int argc, char* argv[])
{
    int numberOfTestCases{0};
    int kingX{0};
    int kingY{0};
    int queenX{0};
    int queenY{0};
    std::string input{""};
    std::string verdict{""};

    std::cout << "Please, input the number of games?";
    std::getline(std::cin, input);
    numberOfTestCases = std::stoi(input);

    std::cout << "Please, give the king and queens coordinates separated by space e.g. (b1 e3):" << std::endl;
    for (int i = 0; i < numberOfTestCases; ++i)
    {
        std::getline(std::cin, input);
        kingX = static_cast<int>(input[1]);
        kingY = static_cast<int>(input[0]);
        queenX = static_cast<int>(input[4]);
        queenY = static_cast<int>(input[3]);

        if (kingX == queenX) verdict += "Y ";
        else if (kingY == queenY) verdict += "Y ";
        else if (std::abs(kingX - queenX) == std::abs(kingY - queenY)) verdict += "Y ";
        else
        {
            verdict += "N ";
        }
    }

    std::cout << verdict << std::endl;

    return 0;
}