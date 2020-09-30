#include <iostream>
#include <vector>
#include <sstream>
#include <string>

int returnSum(std::vector<int>, int);

int main(int argc, char* argv[])
{
    int numberOfTestCases{0};
    std::vector<std::vector<int>> isleChains;
    std::string input{""};

    std::getline(std::cin, input);
    numberOfTestCases = std::stoi(input);

    for (int i = 0; i < numberOfTestCases; ++i)
    {
        int number{0};
        std::vector<int> temp;
        std::getline(std::cin, input);
        std::stringstream str(input);
        while(str >> number)
            temp.emplace_back(number);

        isleChains.emplace_back(temp);
    }


    for(auto chain: isleChains)
    {
        int index{0};
        std::cout << returnSum(chain, index) << " ";
    }

    std::cout << std::endl;

    return 0;
}

int returnSum(std::vector<int> chain, int index)
{
    int sum;

    if (index == (chain.size() - 1))
    {
        sum = chain[index];
    }
    else if (index == (chain.size() - 2))
    {
        sum = chain[index];
    }
    else if (index == (chain.size() - 3))
    {
        sum = chain[index] + returnSum(chain, index+2);
    }
    else 
    {
        sum = returnSum(chain, index+2) > returnSum(chain, index+3) ? returnSum(chain, index+2) : returnSum(chain, index+3);
        sum += chain[index];
    }

    return sum;
}