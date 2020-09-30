#include <iostream>
#include <vector>

int main(int argc, char* argv[])
{
    int numberOfValues{0};
    unsigned long limit{10000007};
    unsigned long multiplier{113};
    unsigned long result{0};
    unsigned long input{0};
    std::vector<unsigned long> arrayOfNumbers;

    std::cout << "Please, enter the lenght of the array: ";
    std::cin >> numberOfValues;

    std::cout << "Enter the values for the array, separated by space:" << std::endl;
    for(int i = 0; i < numberOfValues; ++i)
    {
        std::cin >> input;
        arrayOfNumbers.push_back(input);
    }

    for(auto &value: arrayOfNumbers)
    {
       result = (result + value) * multiplier;

       if(result > limit)
       {
           result %= limit;
       }
    }

    std::cout << result << std::endl;
    
    return 0;
}