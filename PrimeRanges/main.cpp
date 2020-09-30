#include <iostream>
#include <utility>
#include <vector>
#include <string>

bool isPrime(const unsigned int&);
std::string countPrimes(const std::pair<unsigned int, unsigned int>&);

int main()
{
    int numberOfCases{0};
    unsigned int numberOne{0};
    unsigned int numberTwo{0};
    std::vector<std::pair<unsigned int, unsigned int>> primePairs;

    std::cin >> numberOfCases;

    for (int i = 0; i < numberOfCases; ++i)
    {
        std::cin >> numberOne >> numberTwo;
        primePairs.emplace_back(std::make_pair(numberOne, numberTwo));
    }

    for (auto tuple: primePairs)
    {
        std::cout << countPrimes(tuple) << " ";
    }

    std::cout << std::endl;

}

bool isPrime(const unsigned int& number)
{
    if (number <= 3) return (number > 1);
    else if (number == 5 ||number == 7) return true;
    else if (number % 2 == 0 || number % 3 == 0) return false;

    unsigned int i{5};

    do
    {
        if (number % i == 0 || number % (i+2) == 0) return false;
        i++;
    } while (i * i <= number);

    return true;
}

std::string countPrimes(const std::pair<unsigned int, unsigned int> &primePair)
{
    int count{2};
    // std::cout << primePair.first << " " << primePair.second << std::endl;

    for (unsigned int i = primePair.first+1; i < primePair.second; i++)
    {
        if (isPrime(i))
        {
            // std::cout << i << " ";
            ++count;
        }
    }
    // std::cout << std::endl;

    return std::to_string(count);
}