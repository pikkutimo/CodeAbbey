#include <iostream>
#include <string>
#include <vector>
#include <sstream>

int main(int argc, char* argv[])
{
    char signOperator{1};
    unsigned long  value{0};
    unsigned long  result{0};
    unsigned long  modulo{0};
    std::string input;
    std::vector<std::string> calculations;

    std::cout << "Please, input the initial integer: ";
    std::cin >> result;

    std::cout << "Please, input the operation by writing the operator (+/*) followed by the integer:" << std::endl;
    while(signOperator != '%')
    {
        std::cin >> signOperator >> value;
        if (signOperator == '%')
        { 
            modulo=value;
        }
        calculations.push_back(std::to_string(signOperator) + " " + std::to_string(value));
    }

    for(auto &calc: calculations)
    {
        std::stringstream stream(calc);
        std::string temp;
        stream >> temp >> value;
        signOperator =  std::stoi(temp);

        switch(signOperator)
        {
            case '+':
                result += value;
                if (result > modulo)
                {
                    result %= modulo;
                }
                break;
            case '*':
                result *= value;
                if (result > modulo)
                {
                    result %= modulo;
                }
                break;
        }

        stream.str("");
    }

    std::cout << result << std::endl;

    return 0;
}
