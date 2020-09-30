#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <sstream>

bool isTriangle(const int&, const int&, const int&);

int main(int argc, char* argv[])
{
    int numberOfCases{0};
    int firstValue{0};
    int secondValue{0};
    int thirdValue{0};
    
    std::vector<bool> triangleSequence;
    
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

    std::cout << "Please enter the lenght of each side of the candidates" << std::endl;
    std::cin.clear();
    std::cin.ignore();
    
    for (int i=0; i <numberOfCases; ++i){
        std::cin >> firstValue >> secondValue >> thirdValue;
        triangleSequence.push_back(isTriangle(firstValue, secondValue, thirdValue));
    }

    for (auto judgement: triangleSequence){
        std::cout << judgement << " ";
    }

    std::cout << std::endl;

    return 0;
}

bool isTriangle(const int& sideA, const int& sideB, const int& sideC)
{
    if ((sideA+sideB>sideC) && (sideB+sideC>sideA) && (sideA+sideC>sideB))
    {
        return true;
    }

    return false;
}