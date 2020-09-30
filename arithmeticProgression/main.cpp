#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <sstream>

int calculateSequenceSum(int, const int&, const int&);
int main(int argc, char* argv[])
{
    int numberOfCases{0};
    int firstValue{0};
    int sizeOfStep{0};
    int countableElements{0};
    //std::vector<std::string> testCases;
    std::vector<std::string> sequenceSums;
    std::string temp;
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

    std::cout << "Please enter first value of the sequence, size of the step and the number of elements to be counted e.g. 10 1 4" << std::endl;
    std::cin.clear();
    std::cin.ignore();
    
    for (int i=0; i <numberOfCases; ++i){
        std::getline(std::cin, temp);
        std::stringstream stream(temp);
        stream >> firstValue >> sizeOfStep >> countableElements;
        sequenceSums.push_back(std::to_string(calculateSequenceSum(firstValue, sizeOfStep, countableElements)));
    }

    for (auto sum: sequenceSums){
        std::cout << sum << " ";
    }

    std::cout << std::endl;

    return 0;
}

int calculateSequenceSum(int first, const int& step, const int& numberOfSteps)
{
    int sum{0};

    for (int i = 0; i < numberOfSteps; ++i)
    {
        sum += first;
        first += step;
    }

    return sum;
}