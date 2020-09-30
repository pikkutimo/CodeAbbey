#include <iostream>
#include <vector>
#include <cmath>

int corversion(float&);

int main(int charc, char * argv[]){

    auto temp = 0.0;
    auto amount = 0;
    std::vector<float> results;

    std::cout << "Please enter data:";
    std::cin >> amount;

    for (auto i = 0; i < amount; ++i){
        std::cin >> temp;
        results.emplace_back(temp);
    }

    for (auto num: results){
        std::cout << corversion(num) << " ";
    }

    std::cout << std::endl;
    
    return 0;
}

int corversion(float &fahrenheit){
    auto ret = 0;
    ret = std::round((fahrenheit - 32)/1.8);
    return ret;
}