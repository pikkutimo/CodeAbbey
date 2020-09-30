#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

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
    unsigned long secondPrintSpeed{0};
    unsigned long seconds{0};
    std::stringstream stream(input);

    stream >> firstPrintSpeed >> secondPrintSpeed >> numberOfPages;
    
    do
    {
        ++seconds;

        if (seconds%firstPrintSpeed == 0)
        {
            --numberOfPages;
        }
        
        if (seconds%secondPrintSpeed == 0)
        {
            --numberOfPages;
        }

    }while (numberOfPages > 0);

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