#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

void getData(int&, std::vector<std::string>&);
int iterateSequence(std::string&);

int main(int argc, char* argv[])
{
    int iniatialValues{0};
    std::vector<std::string> values;

    getData(iniatialValues, values);

    for (auto& value: values)
    {
        std::cout << iterateSequence(value) << " ";
    }

    std::cout << std::endl;

    return 0;
}

void getData(int& numberOfValues, std::vector<std::string>& vectorOfValues)
{
    std::fstream file;
    std::string temp;

    try
    {
        file.open("data.txt");
        std::getline(file, temp);
        numberOfValues = std::stoi(temp);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "There are " << numberOfValues << " cases in the file." << std::endl;

    std::getline(file, temp);
    file.close();

    std::stringstream stream(temp);

    for (auto i = 0; i < numberOfValues; ++i)
    {
        stream >> temp;
        vectorOfValues.emplace_back(temp);
    }
}

int iterateSequence(std::string& value)
{
    std::vector<int> valueSequence;
    int originalValue = std::stoi(value);
    int iteratorStep{0};

    int numericValue = originalValue;

    while(true)
    {
        valueSequence.emplace_back(numericValue);
        numericValue *= numericValue;
        iteratorStep++;
        value = std::to_string(numericValue);
        if (value.size() <  8)
        {
            int fill = 8 - value.size();
            for (int i = 0; i < fill; ++i)
            {
                value.insert(0, 1, '0');
            }
        }
        
        value = value.substr(2,4);
        numericValue = std::stoi(value);

        auto it = std::find(valueSequence.begin(), valueSequence.end(), numericValue);
        if (it != valueSequence.end()) break;
    }
    
    return iteratorStep;
}