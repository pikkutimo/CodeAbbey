#include <iostream>
#include <cctype>
#include <algorithm>
#include <string>

std::string isPalindrome(std::string&);

int main(int argc, char* argv[])
{
    int numberOfPhrases{0};
    std::string phrase;
    std::string verdict;

    std::getline(std::cin, phrase);
    numberOfPhrases = std::stoi(phrase);

    for (int i = 0; i < numberOfPhrases; ++i)
    {
        std::getline(std::cin, phrase);
        verdict += isPalindrome(phrase);
        verdict += " ";
    }

    std::cout << verdict << std::endl;

    return 0;
}

std::string isPalindrome(std::string& phrase)
{
    phrase.erase(std::remove_if(phrase.begin(), phrase.end(), [](char &ch){
        if (!isalpha(ch)) return true;
        else return false;
    }), phrase.end());

    std::for_each(phrase.begin(), phrase.end(), [](char &c){
        c = ::tolower(c);
    });

    std::string inversePhrase = phrase;
    std::reverse(inversePhrase.begin(), inversePhrase.end());

    if (phrase.compare(inversePhrase) != 0) return "N";

    return "Y";
}
