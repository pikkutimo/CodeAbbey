#include <iostream>
#include <iomanip>
#include <vector>


int main(int argc, char* argv[])
{
    int numberOfTestcases{0};
    std::vector<double> rawCases;
    std::vector<double> smoothedCases;
    double temp{0};

    std::cin >> numberOfTestcases;

    for (int i = 0; i < numberOfTestcases; ++i)
    {
        std::cin >> temp;
        rawCases.emplace_back(temp);
    }

    smoothedCases.emplace_back(rawCases.front());
    for (int i = 1; i < (numberOfTestcases-1); ++i)
    {
        smoothedCases.emplace_back((rawCases[i-1] + rawCases[i] + rawCases[i+1]) / 3.0);
    }
    smoothedCases.emplace_back(rawCases.back());

    for (auto temperature: smoothedCases)
    {
        std::cout << std::setprecision(12) << temperature << " ";
    }

    std::cout << std::endl;

    return 0;
}