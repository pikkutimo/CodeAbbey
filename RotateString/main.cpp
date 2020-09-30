#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

void openData(int&, std::vector<std::string>&);
std::string rotateString(const int&, std::string&);

int main(int argc, char* artgv[])
{
    int numberOfTestCases{0};
    std::vector<std::string> testCases;
    std::string singularCase;
    int k;

    openData(numberOfTestCases, testCases);

    for (auto& test: testCases)
    {
        std::stringstream str(test);
        str >> k >> singularCase;
        test = rotateString(k, singularCase);
        std::cout << test << " ";
    }

    std::cout << std::endl;

    return 0;
}

void openData(int& size, std::vector<std::string>& testCases)
{
    std::string temp;
    std::ifstream file("data.txt");

    if(file.is_open())
    {
        std::getline(file, temp);
        size = std::stoi(temp);

        while(std::getline(file, temp))
        {
            testCases.emplace_back(temp);
        }

        file.close();
    }
    else
    {
        std::cout << "Couldn't open file." << std::endl;
    }
    
}

std::string rotateString(const int& k, std::string& testCase)
{
    char temp;

    if (k > 0)
    {
        for (auto i = 0; i < k; ++i)
        {
            temp = testCase.front();
            testCase.erase(0, 1);
            testCase.append(1,temp);
        }
    }
    else
    {
        for (auto i = std::abs(k); i > 0; --i)
        {
            temp = testCase.back();
            testCase.pop_back();
            testCase.insert(testCase.begin(), temp);
        }
    }
    
    return testCase;
    
}