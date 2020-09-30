#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[])
{
    int index{0};
    int input{0};
    int i{0};
    std::string temp;
    std::vector<std::string> deckOfCards{"CA", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "CT", "CJ", "CQ", "CK",
                                        "DA", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "DT", "DJ", "DQ", "DK",
                                        "HA", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "HT", "HJ", "HQ", "HK",
                                        "SA", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "ST", "SJ", "SQ", "SK",
                                        };

    for (int i = 0; i < 52; ++i)
    {
        std::cin >> input;
        input %= 52;
        temp = deckOfCards[i];
        deckOfCards[i] = deckOfCards[input];
        deckOfCards[input] = temp;
    }

    for (auto card: deckOfCards)
    {
        std::cout << card << " ";
    }
    
    std::cout << std::endl;

    return 0;
}