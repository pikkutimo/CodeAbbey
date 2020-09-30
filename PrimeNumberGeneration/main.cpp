#include <iostream>
#include <vector>
#include <cmath>

void printPrimes(const std::vector<int>, const int&);

int main(int argc, char* argv[])
{
    int numberOfCases{0};
    int input{0};
    int maxIndex{0};
    std::vector<int> indices;

    std::cin >> numberOfCases;

    for (int i = 0; i < numberOfCases; ++i)
    {
        std::cin >> input;
        if (input > maxIndex) maxIndex = input;
        indices.emplace_back(input);
    }

    printPrimes(indices, maxIndex);

    std::cout << std::endl;

    return 0;
}

void printPrimes(const std::vector<int> indices, const int& lastIndex)
{
    unsigned int biggestPrime{2750159};
    unsigned int count{0};
    std::vector<bool> isPrime(biggestPrime, true);
    isPrime[0] = isPrime[1] = false;

    for (unsigned int i = 2; i*i <= biggestPrime; i += 1)
    {
        if (isPrime[i] == true)
        {
            for (unsigned int j = i + i; j <= biggestPrime; j += i)
            {
                isPrime[j] = false;
            }

            count++;
            if (count == lastIndex) break;
        }
        else continue;
    }

    std::vector<unsigned int> primeVector;
    primeVector.emplace_back(0);

    for (unsigned int i = 2; i < biggestPrime; ++i)
    {
        if(isPrime[i])
        {
            primeVector.emplace_back(i);
        }
    }

    for (auto index: indices)
    {
        std::cout << primeVector[index] << " ";
    }

    std::cout << std::endl;

}