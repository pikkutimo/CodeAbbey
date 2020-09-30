#include <iostream>
#include <vector>
#include <iomanip>

double calculateSquareRoot(const int&, const int&);

int main(int argc, char* argv[])
{
    int numberOfCases{0};
    int xValue{0};
    int numberOfCalculations{0};
    bool notValid{true};
    std::vector<double> squareRoots;

    std::cout << "Please, enter the number of test-cases:\n";
    std::cin >> numberOfCases;
       

    std::cout << "Please input both the X and the number of steps in the calculation for each test-case:" << std::endl;

    for (int i = 0; i < numberOfCases; ++i)
    {
        std::cin >> xValue >> numberOfCalculations;
        squareRoots.push_back(calculateSquareRoot(xValue, numberOfCalculations));
    }

    std::cout << std::setprecision(12);

    for(auto root: squareRoots)
    {
        std::cout << root << " ";
    }

    std::cout << std::endl;

    return 0;
}

double calculateSquareRoot(const int& numberToBeSquared, const int& numberOfCalculations)
{
    double root{1};
    double number = static_cast<double>(numberToBeSquared);

    for(auto i = 0; i < numberOfCalculations; ++i)
    {
        root = (root + number/root)/2;
    }

    return root;
}

// 3.60555127546 21.4604386887 9.53939201417 45.3661549266 8859.99997178 1393.54616121 21.5174347914 32836.5 98.4437720657 28.4956145874

// 10
// 13 13
// 456 6
// 91 12
// 643 4
// 35435 2
// 44253 5
// 463 9
// 65672 1
// 9690 9
// 812 8