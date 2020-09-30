#include <iostream>
#include <array>

int main(int argc, char* argv[])
{
    std::array<int, 300> valueArray;
    int maxValue{0};
    int minValue;

    std::cout << "Please, input the values for the array: " << std::endl;

    for(int i = 0; i < 300; ++i)
    {
        std::cin >> valueArray[i];
        if (i == 0) minValue = valueArray[0];
        if(valueArray[i] > maxValue) maxValue=valueArray[i];
        if(valueArray[i] < minValue) minValue=valueArray[i];
    }

    std::cout << maxValue << " " << minValue << std::endl;

    return 0;
}
