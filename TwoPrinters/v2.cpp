#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <cmath>

int getMinimumTime(std::string& input);

int main(int argc, char* argv[])
{
    std::string temp;
    std::fstream file;
    int numberOfCases{0};

    std::cout << "Reading the data from file." << std::endl;
    
    try
    {
        file.open("data.txt");
        std::getline(file, temp);
        numberOfCases = std::stoi(temp);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "There are " << numberOfCases << " cases in the file." << std::endl;

    while(std::getline(file, temp))
    {
        std::cout << getMinimumTime(temp) << " ";
    }

    file.close();
    
    std::cout << std::endl;

    return 0;
}

int getMinimumTime(std::string& input)
{
    unsigned long numberOfPages{0};
    unsigned long firstPrintSpeed{0};
    int pagesForFirst{0};
    unsigned long secondPrintSpeed{0};
    int pagesForSecond{0};
    unsigned long seconds{0};
    std::stringstream stream(input);

    stream >> firstPrintSpeed >> secondPrintSpeed >> numberOfPages;
    
    pagesForFirst = std::ceil(1.0 * secondPrintSpeed*numberOfPages / (firstPrintSpeed+secondPrintSpeed));
    pagesForSecond = std::floor(1.0*firstPrintSpeed*numberOfPages / (firstPrintSpeed+secondPrintSpeed));

    seconds = pagesForFirst * firstPrintSpeed + pagesForSecond * secondPrintSpeed;

    firstPrintSpeed > secondPrintSpeed? seconds+=secondPrintSpeed: seconds += firstPrintSpeed; 

    return seconds;
}

// 3 5 4
// 1   -
// 2   -
// 3   1 page printed
// 4   -
// 5   second page printed
// 6   third page printed
// 7   -
// 8   -
// 9   final page printed
// 10