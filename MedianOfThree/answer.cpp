#include <iostream>
#include <vector>

int main(int argc, char *argv[]){

    auto cases = 0;
    auto number1 = 0;
    auto number2 = 0;
    auto number3 = 0;
    std::vector<int> result;

    std::cout << "How many triplets? ";
    std::cin >> cases;

    std::cout << "Please, input the triplets:" << std::endl;
    for (auto i = 0 ; i < cases ; ++i){
        std::cin >> number1 >> number2 >> number3;
        
        if (number1 > number2)
        {
            number1 += number2;
            number2 = number1 - number2;
            number1 -= number2;
        }
        if (number2 > number3)
        {
            number2 += number3;
            number3 = number2 - number3;
            number2 -= number3;
        }
        if (number1 > number2)
        {
            number1 += number2;
            number2 = number1 - number2;
            number1 -=number2;
        }

        result.emplace_back(number2);
    }

    for(auto numb : result){
        std::cout << numb << " ";
    }

    std::cout << std::endl;

    return 0;
}