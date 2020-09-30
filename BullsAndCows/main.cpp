#include <iostream>
#include <string>
#include <vector>

constexpr int strLenght{4};

void getBullsAndCows(const std::string&, const std::string&);

int main(int argc, char* argv[])
{
    std::string secretNumber{""};
    std::string answer{""};
    std::vector<std::string> playerAnswers;
    int numberOfGuesses{0};

    std::cin >> secretNumber >> numberOfGuesses;
    for (int i = 0; i < numberOfGuesses; ++i)
    {
        std::cin >> answer;
        getBullsAndCows(secretNumber, answer);
    }

    std::cout <<  std::endl;
    return 0;
}

void getBullsAndCows(const std::string& secret, const std::string& answer)
{
    int correctLetter{0};
    int correctPosition{0};

    for (int i = 0; i < strLenght; ++i)
    {
        if (secret[i] == answer[i]) ++correctPosition;
        else
        {
            std::string::size_type position = secret.find(answer[i]);
            if (position != std::string::npos) ++correctLetter;
        }
    }
    
    std::cout << std::to_string(correctPosition) << "-" << std::to_string(correctLetter) << " ";
}