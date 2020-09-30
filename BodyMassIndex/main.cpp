#include <iostream>
#include <string>
#include <sstream>

void getBMI(const double&, const double&, std::string&);

int main(int charc, char* argv[])
{
    int numberOfSubjects{0};
    double subjectWeight{0};
    double subjectHeight{0};
    std::string input;
    std::string results = "";

    std::cout << "Please input the number of subjects: ";
    std::getline(std::cin, input);
    numberOfSubjects = std::stoi(input);

    std::cout << "\nInput the weight in kilograms and height in metres for each subject:" << std::endl;

    for(auto i=0; i<numberOfSubjects; ++i)
    {
        std::getline(std::cin, input);
        std::stringstream stream(input);
        stream >> subjectWeight >> subjectHeight;
        getBMI(subjectWeight, subjectHeight, results);
    }

    std::cout << results << std::endl;

    return 0;
}

void getBMI(const double& weight, const double& height, std::string& results)
{
    double bodyMassIndex = (weight / (height * height));

    if (bodyMassIndex < 18.5) results += "under ";
    else if (bodyMassIndex < 25.0) results += "normal ";
    else if (bodyMassIndex < 30.0) results += "over ";
    else results += "obese ";
}
