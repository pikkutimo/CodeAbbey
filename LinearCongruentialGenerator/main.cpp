#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

void getData(int&, std::vector<std::string>&);
int getNthValue(const std::string&);

int main(int argc, char* argv[])
{
    std::vector<std::string> tests;
    int numberOfTests{0};

    getData(numberOfTests, tests);

    for(auto test: tests)
    {
        std::cout << getNthValue(test) << " ";
    }

    std::cout << std::endl;

    return 0;
}

void getData(int& numberOfTests, std::vector<std::string>& testData)
{
    std::ifstream file("data.txt");
    if (file.is_open()) {
        std::string line;
        std::getline(file, line);
        numberOfTests = std::stoi(line);
        while (std::getline(file, line))
        {
            testData.push_back(line);
        }
        file.close();
    }

}

int getNthValue(const std::string& testCase)
{
    int multiplier{0};
    int constant{0};
    int currentX{0};
    int modulo{0};
    int n{0};
    std::stringstream str(testCase);

    str >> multiplier >> constant >> modulo >> currentX >> n; 

    for (int i = 0; i < n; ++i)
    {
        currentX = (multiplier * currentX + constant) % modulo;
    }

    return currentX;
}