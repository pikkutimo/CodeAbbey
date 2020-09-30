#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>

void sortByVolatility(std::vector<std::string> *);

int main(int argc, char *argv[])
{
    int numberOfStocks{0};
    std::string input;
    std::vector<std::string> nameAndFortnightPrices;

    std::getline(std::cin, input);
    numberOfStocks = std::stoi(input);

    for (int i = 0; i < numberOfStocks; ++i)
    {
        std::getline(std::cin, input);
        nameAndFortnightPrices.emplace_back(input);
    }

    sortByVolatility(&nameAndFortnightPrices);

    std::cout << std::endl;

    return 0;
}

void sortByVolatility(std::vector<std::string> *nameAndPrices)
{
    std::string result;
    std::string name;
    std::string input;
    std::vector<float> prices;
    float temp{0};
    float meanPrice{1.0};
    float squaredMean{1.0};
    float standardDeviation{0};
    float dealerCommission{0.01};


    for (auto &stock: *nameAndPrices)
    {
        std::stringstream str(stock);
        str >> name;
        
        for (int i = 0; i < 14; ++i)
        {
            str >> input;
            prices.emplace_back(std::stof(input));
            meanPrice += std::stof(input);
        }

        meanPrice /= 14;

        for (auto &price: prices)
        {
            temp = price - meanPrice;
            price = temp * temp;
            squaredMean += price;
        }

        squaredMean /= 14;
        standardDeviation = sqrt(squaredMean);

        if (standardDeviation > (4 * dealerCommission * meanPrice))
        {
            std::cout << name << " ";
        }

        prices.clear();
        squaredMean = 0;
        meanPrice = 0;
    }
}