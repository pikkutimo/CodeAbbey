#include <iostream>
#include <string>
#include <cctype>
#include <sstream>

std::string decode(const std::string&, const int&);
int main(int argc, char* argv[])
{
    int numberOfLines{0};
    int stepK{0};
    std::string temp;
    std::string decryptedMessage{""};

    std::getline(std::cin, temp);
    std::stringstream str(temp);
    str >> numberOfLines >> stepK;

    for (int i = 0; i < numberOfLines; ++i)
    {
        std::getline(std::cin, temp);
        decryptedMessage += decode(temp, stepK);
    }

    std::cout << decryptedMessage << std::endl;

    return 0;
}

std::string decode(const std::string& encryptedString, const int& stepK)
{
    const std::string alphabet{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    constexpr int lenghtOfAlphabet{26};
    std::string temp;

    for (auto symbol: encryptedString)
    {
        if (isalpha(symbol))
        {
            for (int i = 1; i <= lenghtOfAlphabet; ++i)
            {
                if (symbol == alphabet[i])
                {
                    if (i - stepK < 0)
                    {
                        temp += alphabet[lenghtOfAlphabet + i - stepK];
                    }
                    else
                    {
                        temp += alphabet[i - stepK];
                    }
                    
                }
            }
        }
        else
        {
            temp += symbol;
        }
        
    }

    temp += " ";
    return temp;
}