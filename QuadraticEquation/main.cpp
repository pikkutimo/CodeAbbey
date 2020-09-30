#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>

void solveEquation(std::vector<std::string> *);

int main(int argc, char* argv[])
{
    int numberOfTestCases{0};
    std::vector<std::string> testCases;
    std::string input;

    std::cout << "Please, input the number of cases: " << std::endl;
    std::getline(std::cin, input);

    std::cout << "Please input the coefficients for each testcase separated by space (e.g. 1 2 3):" << std::endl;
    numberOfTestCases = std::stoi(input);

    for (int i = 0; i < numberOfTestCases; ++i)
    {
        std::getline(std::cin, input);
        testCases.emplace_back(input);
    }

    solveEquation(&testCases);

    return 0;
}

void solveEquation(std::vector<std::string> *testCases)
{
    int A{0};
    int B{0};
    int C{0};
    int counter = testCases->size();
    float discriminant{0};
    float firstRoot{0};
    float secondRoot{0};
    float imaginary{0};

    // std::cout << "In solver... " << counter << std::endl;
    for (std::string test: *testCases)
    {
        std::stringstream str(test);
        str >> A >> B >> C;
        // std::cout << A << " " << B << " " << C << std::endl;

        discriminant = B * B - 4 * A * C;

        if (discriminant > 0) //2 distinct roots
        {
            firstRoot = (-B + sqrt(std::abs(discriminant)))/(2 *A);
            secondRoot = (-B - sqrt(std::abs(discriminant)))/(2 *A);

            std::cout << firstRoot << " " << secondRoot;
        }
        else if (discriminant == 0) // exactly 1 root
        {
            firstRoot = -B / (2 * A);
            
            std::cout << firstRoot << " " << firstRoot;
        }
        else //while discriminant is negative, the two roots are complex
        {
            firstRoot = -B / (2 * A);
            imaginary = sqrt(-discriminant)/(2 * A);

            std::cout << firstRoot << "+" << imaginary << "i " << firstRoot << "-" << imaginary << "i";
        }

        counter--;

        if (counter != 0){
            std::cout << "; ";
        }
    }

    std::cout << std::endl;
}