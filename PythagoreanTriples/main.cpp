#include <iostream>
#include <cmath>
#include <vector>
#include <string>

std::string findHypotenuse(unsigned long long&);

int main(int argc, char* argv[])
{
    int numberOfCase{0};
    unsigned long long sum{0};
    std::vector<std::string> solutions;

    std::cin >> numberOfCase;

    for (int i = 0; i < numberOfCase; ++i)
    {
        std::cin >> sum;
        solutions.emplace_back(findHypotenuse(sum));
    }

    for (auto answer: solutions)
    {
        std::cout << answer << " ";
    }

    std::cout << std::endl;

    return 0;
}

std::string findHypotenuse(unsigned long long& sum)
{
    //a^2 + b^2 = c^2
    //a + b + c = sum => c = sum - a - b
    //
    // => a^2 + b^2 = sum - a - b
    // => b = (sum * sum - 2 * sum * a) / (2 * sum - 2 * a)
    // => 

    for (unsigned long long a = 1; a <= sum; a++) 
    { 
        // Calculate value of b 
        unsigned long long b = (sum * sum - 2 * sum * a) / (2 * sum - 2 * a); 
  
        // The value of c = n - a - b 
        unsigned long long c = sum - a - b; 
  
        if (a * a + b * b == c * c  && b > 0 && c > 0) 
        { 
            return std::to_string(c * c);
            break; 
        } 
    } 

    return std::to_string(sum);

}