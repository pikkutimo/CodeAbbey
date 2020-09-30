#include <iostream>
#include <vector>
#include <string>

int getWeightedSum(int&);

int main(int argc, char* argv[])
{
    int numberOfCases{0};
    int temp{0};

    std::vector<int> weightedSumsOfDigits;
    
    bool notValid{true};

    std::cout << "Please, enter the number of test-cases:\n";
    while(notValid)
    {
        std::cin >> numberOfCases;
        if(std::cin.fail()){
            std::cout << "Please enter integer value." << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
        else
        {
            notValid = false;
        }
        
    }

    std::cout << "Please enter the values separated by space (e.g. 1 2 3):" << std::endl;
  
    for (int i=0; i <numberOfCases; ++i){
        std::cin >> temp;
        weightedSumsOfDigits.push_back(getWeightedSum(temp));
    }

    for (auto sum: weightedSumsOfDigits){
        std::cout << sum << " ";
    }

    std::cout << std::endl;

    return 0;
}

int getWeightedSum(int& number)
{
    int singleDigit{0};
    int multiplier{1};
    int weightedSum{0};
    std::vector<int> digits;

    while(number > 0)
    {
        singleDigit = number%10;
        digits.insert(digits.begin(), singleDigit);
        number -= singleDigit;
        number /= 10;
    }

    for (auto digit: digits)
    {
        weightedSum += multiplier*digit;
        ++multiplier;
    }

    return weightedSum;

}