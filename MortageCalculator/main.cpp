#include <iostream>
#include <cmath>

int main(int argc, char* argv[])
{
    int loanCapital{0};
    int interestRate{0};
    int monthsToPayUp{0};

    std::cin >> loanCapital >> interestRate >> monthsToPayUp;

    float monthlyPayment{0};
    float monthlyInterest = 1.0*interestRate/12;
    float intermediateInterest = 1 + monthlyInterest/100;

    monthlyPayment = (loanCapital * pow(intermediateInterest, monthsToPayUp) * (monthlyInterest/100))/(pow(intermediateInterest, monthsToPayUp) - 1);

    std::cout << std::ceil(monthlyPayment) << std::endl;

    return 0;
}