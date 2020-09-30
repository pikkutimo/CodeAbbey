#include <iostream>
#include <vector>

int countSteps(int&);

int main(int argc, char* argv[])
{
    int numberOfCases{0};
    std::vector<int> stepsPerCase;;

    std::cin >> numberOfCases;
    for (int i = 0; i < numberOfCases; ++i)
    {
        int temp;
        std::cin >> temp;
        stepsPerCase.emplace_back(countSteps(temp));    
    }

    for (auto steps: stepsPerCase)
    {
        std::cout << steps << " ";
    }

    std::cout << std::endl;

    return 0;
}

int countSteps(int& number)
{
    int steps{0};

    while(number != 1)
    {
        if (number % 2 == 0)
        {
            number /= 2;
        }
        else
        {
            number = number * 3 + 1;
        }
        ++steps;
    }

    return steps;
}