#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

bool isPrime(const unsigned long long&);
std::string searchFactors(unsigned long long&);

int main(int argc, char* argv[])
{
    int numberOfCases{0};
    unsigned long long input;
    std::vector<unsigned long long> cases;

    std::cin >> numberOfCases;

    for (int i = 0; i < numberOfCases; ++i)
    {
        std::cin >> input;
        cases.emplace_back(input);
    }

    for (auto number: cases)
    {
        std::cout << searchFactors(number) << " ";
    }

    std::cout << std::endl;

    return 0;
}

bool isPrime(const unsigned long long& number)
{
    if (number <= 3) return (number > 1);
    else if (number == 5 ||number == 7) return true;
    else if (number % 2 == 0 || number % 3 == 0) return false;

    unsigned long long i{5};

    do
    {
        if (number % i == 0 || number % (i+2) == 0) return false;
        i++;
    } while (i * i <= number);

    return true;
}

std::string searchFactors(unsigned long long& noToFactorize)
{
    std::vector<unsigned long long> factors;

    // Check if number itself is prime
    if (isPrime(noToFactorize))
    {
        return std::to_string(noToFactorize);
    }
    
    while(noToFactorize % 2 == 0)
    {
        factors.emplace_back(2);
        noToFactorize /= 2;
    }

    for (auto i = 3; i <= sqrt(noToFactorize); i += 2)
    {
        if(isPrime(i))
        {
            while(noToFactorize % i == 0)
            {
                factors.emplace_back(i);
                noToFactorize /= i;
            }
        }
    }

    if (noToFactorize > 2)
    {
        factors.emplace_back(noToFactorize);
    }

    std::sort(factors.begin(), factors.end());
    std::string toReturn;
    int index{0};
    

    for (auto factor: factors)
    {
        index++;
        toReturn += std::to_string(factor);
        if (index != factors.size())
        {
            toReturn += "*";
        }
        else
        {
            toReturn += " ";
        }
    }

    return toReturn;

}