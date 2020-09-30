#include <iostream>
#include <string>
#include <vector>

int counVowels(const std::string&);

int main(int argc, char* argv[])
{
    int numberOfTestCases{0};
    std::vector<int> vowelsInTestCases;
    std::string input;

    std::cout << "Please, input the number of test-cases: ";
    std::getline(std::cin, input);

    numberOfTestCases = std::stoi(input);

    for (auto i = 0; i < numberOfTestCases; ++i)
    {
        std::getline(std::cin, input);
        vowelsInTestCases.push_back(counVowels(input));
    }

    for (auto count: vowelsInTestCases){
        std::cout << count << " ";
    }

    std::cout << std::endl;
    return 0;
}

int counVowels(const std::string& testCase)
{
    std::string vowels = "aouiey";
    int numberOfVowels{0};

    for (auto it = testCase.begin(); it != testCase.end(); ++it)
    {
        if (vowels.find(*it) != std::string::npos) ++numberOfVowels;
    }

    return numberOfVowels;
}