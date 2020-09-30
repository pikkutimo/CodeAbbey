#include <iostream>
#include <vector>
#include <cmath>

int main(int charc, char * argv[]){
    auto number1 = 0.0;
    auto number2 = 0.0;
    auto temp = 0.0;
    auto amount = 0;
    std::vector<float> results;

    std::cout << "How many pairs? ";
    std::cin >> amount;

    std::cout << std::endl << "Please enter the pairs:" << std::endl;

    for (auto i = 0; i < amount; ++i){
        std::cin >> number1 >> number2;
        temp = number1/number2;
        results.emplace_back(temp);
    }

    for (auto num: results){
        std::cout << std::round(num) << " ";
    }

    std::cout << std::endl;
    
    return 0;
}
