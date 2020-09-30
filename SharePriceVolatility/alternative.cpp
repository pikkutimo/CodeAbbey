#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

template<typename InputIt, typename BinaryOperation = decltype(std::plus<>())>
double average(InputIt first, InputIt last, BinaryOperation op = std::plus<>())
{
    return std::accumulate(first, last, 0.0, op) / std::distance(first, last);
}

double quadratic_distance(const double element, const double average)
{
    return std::pow(average - element, 2);
}

template<typename InputIt>
double deviation(InputIt first, InputIt last, const double meanValue)
{
    return std::sqrt(average(first, last, [&meanValue](auto total, auto current)
        {
            return total + quadratic_distance(current, meanValue);
        }));
}

int main()
{
    int number_of_lines = 0;
    std::cin >> number_of_lines;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::vector<std::string> results;
    for(std::string current_line; number_of_lines && std::getline(std::cin, current_line); --number_of_lines)
    {
        std::stringstream ss(current_line);
        std::string stock_name;
        ss >> stock_name;

        std::vector<int> values{std::istream_iterator<int>(ss), std::istream_iterator<int>()};
        
        const auto mean_price = average(values.cbegin(), values.cend());
        const auto minimal_volatility = mean_price / 25.0;
        
        const auto volatility = deviation(values.cbegin(), values.cend(), mean_price);
        if(volatility >= minimal_volatility)
        {
            results.emplace_back(std::move(stock_name));
        }
    }

    std::copy(std::begin(results), std::end(results), std::ostream_iterator<std::string>(std::cout, " "));
}