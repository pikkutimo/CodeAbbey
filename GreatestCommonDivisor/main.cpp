#include <iostream>
#include <vector>
#include <utility>
#include <sstream>
#include <fstream>
#include <string>

void readFromFile(int&, std::vector<std::pair<int,int>>&);
int getGreatestCommonDivisor(std::pair<int,int>);
int getLeastCommonMultiple(const std::pair<int, int>&, const int&);


int main(int argc, char* argv[])
{
    int numberOfTestcases{0};
    std::vector<std::pair<int,int>> testCases;

    readFromFile(numberOfTestcases, testCases);

    for(std::pair tuple: testCases)
    {
        int greatestCommonDivisor = getGreatestCommonDivisor(tuple);

        std::cout << "(" << greatestCommonDivisor << " " << getLeastCommonMultiple(tuple, greatestCommonDivisor) << ") "; 
    }

    std::cout << std::endl;
    
    return 0;
}

void readFromFile(int& numberOfTestCases, std::vector<std::pair<int,int>>& testCases)
{
    int numberOne{0};
    int numberTwo{0};
    
    std::ifstream file;
    file.open("data.txt");

    if (file.is_open())
    {
        std::string line;
        std::getline(file, line);
        numberOfTestCases = std::stoi(line);

        while(std::getline(file, line))
        {
            std::stringstream filestream(line);
            filestream >> numberOne >> numberTwo;
            testCases.emplace_back(std::make_pair(numberOne, numberTwo));
        }

        file.close();
       
    }
    else
    {
        std::cout << "Could not open file." << std::endl;
    }
}

int getGreatestCommonDivisor(std::pair<int, int> testCase)
{
    while(testCase.first != testCase.second)
    {
        if (testCase.first > testCase.second)
        {
            testCase.first -= testCase.second;
        }
        else
        {
            testCase.second -= testCase.first;
        }
    }

    return testCase.first;
}

int getLeastCommonMultiple(const std::pair<int, int>& testCase, const int& gcd)
{
    return testCase.first * testCase.second / gcd; 
}