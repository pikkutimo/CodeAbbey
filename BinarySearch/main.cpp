#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <string>

void readFile(int&, std::vector<std::string>&);
void solveEquation(std::string&);

int main(int argc, char* argv[])
{
    std::vector<std::string> testVariables;
    std::vector<std::string> testResults;
    int numberOfTestCases{0};

    readFile(numberOfTestCases, testVariables);

    for (auto test: testVariables)
    {
        solveEquation(test);
    }

    std::cout << std::endl;
    return 0;
}

void readFile(int& cases, std::vector<std::string>& testVariables)
{
    std::ifstream file("data.txt");
    std::string temp;

    if (file.is_open())
    {
        std::getline(file, temp);
        cases = std::stoi(temp);
        
        while(std::getline(file, temp))
        {
            testVariables.emplace_back(temp);
        }

        file.close();
    }
    else
    {
        std::cout << "Couldn't open the file spesified." << std::endl;
    }
    
}

void solveEquation(std::string& testCase)
{
    double A{0};
    double B{0};
    double C{0};
    double D{0};
    double X;
    double result{1};
    double rangeStart{0.0};
    double rangeEnd{100.0};
    std::stringstream stream(testCase);

    stream >> A >> B >> C >> D;

    while(std::fabs(result) >= 0.0000001)
    {
        X = rangeStart + (rangeEnd - rangeStart)/2;

        // std::cout << std::setprecision(12) <<  rangeStart << " " << X << " " << rangeEnd;

        result = A * X + B * sqrt(pow(X, 3)) - C * exp(-X/50) - D;

        // std::cout << " " << result << std::endl;
        if (result < 0)
        {
            // std::cout << "Smaller than - ";
            rangeStart = X;    
            
        }
        else
        {
            // std::cout << "Larger than - ";
            rangeEnd = X;
        }
    }

    std::cout << std::setprecision(15) << X << " " ;
    // A * x + B * sqrt(x ^ 3) - C * exp(-x / 50) - D = 0
   
}

// 9.25185889669 37.8160479212 13.234268901 85.5907316462 21.321827423 92.5679553382 74.6866866898
// 9.25185889645945 37.81604791875 13.234268897213 85.5907316959929 21.3218274409883 92.5679552135989 74.686686595669
