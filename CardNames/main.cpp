#include <iostream>
#include <string>
#include <vector>

std::string getSuitAndRank(int&);

int main(int argc, char* argv[])
{
    int numberOfCards{0};
    int givenCard{0};
    std::string cards;

    std::cin >> numberOfCards;

    for (int i = 0; i < numberOfCards; ++i)
    {
        std::cin >> givenCard;
        cards += getSuitAndRank(givenCard);
    }

    std::cout << cards << std::endl;

    return 0;
}

std::string getSuitAndRank(int& card)
{
    std::vector<std::string> suits {"Clubs", "Spades", "Diamonds", "Hearts"};
    std::vector<std::string> ranks {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};

    int suit = card / 13;
    int rank = card % 13;

    std::string answer = ranks[rank] + "-of-" + suits[suit] + " ";
    return answer;
}