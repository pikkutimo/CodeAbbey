#include <iostream>
#include <iomanip>
#include <vector>

double getDistance(int, int&, int&);

int main()
{
    int numberOfCases{0};
    int distance{0};
    int firstSpeed{0};
    int secondSpeed{0};
    std::vector<double> results;

    std::cin >> numberOfCases;

    for(int i = 0; i < numberOfCases; ++i)
    {
        std::cin >> distance >> firstSpeed >> secondSpeed;
        results.emplace_back(getDistance(distance, firstSpeed, secondSpeed));
    }

    for (auto result : results)
    {
        std::cout << std::setprecision(12) << result << " ";
    }

    std::cout << std::endl;

    return 0;
}

double getDistance(int distance, int& firstSpeed, int& secondSpeed)
{
    double time = 1.0 * distance / (firstSpeed + secondSpeed);

    return (time * firstSpeed);
}