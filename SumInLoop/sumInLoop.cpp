#include <iostream>
//#include <string>

int main(int argc, char *argv[]){

    /*std::string numbers;
    std::string temp;
    int sum = 0;

    std::cout << "\nInput the list of numbers: ";
    std::getline(std::cin, numbers);

    for (auto ch : numbers){
        if (ch == ' ' ){
            sum += std::stoi(temp);
            temp.clear();
        }
        temp += ch;
    }

    sum += std::stoi(temp);*/

    auto sum = 0;
    auto temp = 0;
    auto amount = 0;

    std::cout << "How many numbers are there? ";
    std::cin >> amount;

    for (auto i = 0 ; i < amount ; ++i){
        std::cout << "Input the number: ";
        std::cin >> temp;
        sum += temp;
    }

    std::cout << "\nThe sum = " << sum << std::endl;

    return 0;
}