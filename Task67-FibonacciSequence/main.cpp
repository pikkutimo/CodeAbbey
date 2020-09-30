#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

int findIndex(const std::string&);

int main()
{
    int amountOfNumbers{0};
    std::vector<std::string> sequences;
    std::string lineInput;

    std::getline(std::cin, lineInput);
    amountOfNumbers = std::stoi(lineInput);

    for (int i = 0; i < amountOfNumbers; ++i)
    {
        std::getline(std::cin, lineInput);
        sequences.emplace_back(lineInput);
    }

    for (auto line: sequences)
    {
        std::cout << findIndex(line) << " ";
    }

    std::cout << std::endl;

}

int findIndex(const std::string& number)
{
    int index{0};
    int carry{0};
    int sum{0};
    int len = number.length();
    std::vector<int> a(len, 0);
    std::vector<int> b(len, 0);
    std::string fibonacci;

    if (number == "0")
        return index;

    a[0] = 1;
    b[0] = 1;
    index = 1;

    while(fibonacci != number)
    {
        fibonacci.clear();

        for (int i = 0; i < len; ++i)
        {
            sum = a[i] + b[i] + carry;
            carry = 0;
            if (sum > 9)
            {
                carry = sum / 10;
                sum = sum - (carry * 10);
            }
            
            a[i] = b[i];
            b[i] = sum;
        }

        for (auto digit: a)
        {
            fibonacci += std::to_string(digit);
        }

        std::reverse(fibonacci.begin(), fibonacci.end());

        index++;
    }

    return index;

}