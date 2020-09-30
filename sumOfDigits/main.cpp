#include <iostream>
#include <vector>
#include <string>

int getSum(const int&, const int&, const int&);

int main(int argc, char* argv[])
{
    int numberOfCases{0};
    int a{0};
    int b{0};
    int c{0};

    std::vector<int> sumsOfDigits;
    
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

    std::cout << "Please enter the values for a, b and c in order (e.g. 1 2 3):" << std::endl;
  
    for (int i=0; i <numberOfCases; ++i){
        std::cin >> a >> b >> c;
        sumsOfDigits.push_back(getSum(a, b, c));
    }

    for (auto sum: sumsOfDigits){
        std::cout << sum << " ";
    }

    std::cout << std::endl;

    return 0;
}

int getSum(const int& a, const int& b, const int& c)
{
    int result = a*b+c;
    int singleDigit{0};
    int sumOfDigits{0};

    std::cout << result << std::endl;

    while(result > 0)
    {
        singleDigit = result%10;
        sumOfDigits += singleDigit;
        result -= singleDigit;
        result /= 10;
    }

    return sumOfDigits;
}