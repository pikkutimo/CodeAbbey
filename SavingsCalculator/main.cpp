#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <string>

void readFile(int&, std::vector<std::string>&);
int calculateYears(std::string&);

int main(int argc, char* argv[])
{
    std::vector<std::string> accountVariables;
    int numberOfTestCases{0};

    readFile(numberOfTestCases, accountVariables);

    for (auto testCase: accountVariables)
    {
        std::cout << calculateYears(testCase) << " ";
    }

    std::cout << std::endl;
    return 0;
}

void readFile(int& cases, std::vector<std::string>& accountVariables)
{
    std::ifstream file("data.txt");
    std::string temp;

    if (file.is_open())
    {
        std::getline(file, temp);
        cases = std::stoi(temp);
        
        while(std::getline(file, temp))
        {
            accountVariables.emplace_back(temp);
        }

        file.close();
    }
    else
    {
        std::cout << "Couldn't open the file spesified." << std::endl;
    }
    
}

int calculateYears(std::string& accountParameters)
{
    float capital{0};
    float goal{0};
    float apr{0};
    int years{0};
    int temp;

    std::stringstream account(accountParameters);
    account >> capital >> goal >> apr;

    float modifiedInterest = apr/100 + 1.0;

    while (capital < goal)
    {
        capital *= modifiedInterest;
        temp = static_cast<int>(capital*100);
        capital = static_cast<float>(1.0*temp/100);
        ++years;
    }

    return years;

}