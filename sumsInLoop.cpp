#include <iostream>
#include <vector>

int main(int argc, char *argv[]){
    auto pairs = 0;
    auto number1 = 0;
    auto number2 = 0;
    std::vector<int> result;
    std::cout <<  "How many pairs? ";
    std::cin >> pairs;

    std::cout << std::endl << "Please, input the pairs: ";
    for (auto i = 0; i < pairs ; ++i){
        std::cin >> number1 >> number2;
        result.emplace_back(number1 + number2);
    }

    for (auto number : result){
        std::cout << number << " ";
    }

    std::cout << std::endl;

    return 0;
}