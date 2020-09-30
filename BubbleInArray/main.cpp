#include <iostream>
#include <vector>

int calculateChecksum(std::vector<int>&);
int bubbleSort(std::vector<int>&);

int main(int argc, char* argv[])
{
    std::vector<int> numbers;
    int input{0};
    int performedSwaps{0};
    int arrayChecksum{0};

    while (true)
    {
        std::cin >> input;
        if (input == -1) break;
        numbers.emplace_back(input);
    }

    std::cout << bubbleSort(numbers) << " " << calculateChecksum(numbers) << std::endl;
    
    return 0;
}

int calculateChecksum(std::vector<int>& numberArray)
{
    constexpr int limit{10000007};
    constexpr int multiplier{113};
    int arrayChecksum{0};

    for(auto &value: numberArray)
    {
       arrayChecksum = (arrayChecksum + value) * multiplier;

       if(arrayChecksum > limit)
       {
           arrayChecksum %= limit;
       }
    }

    return arrayChecksum;
}

int bubbleSort(std::vector<int>& numberArray)
{
    int swaps{0};
    int temp{0};

    for (auto i = 1; i < numberArray.size(); ++i)
    {
        if (numberArray[i] < numberArray[i - 1]){
            temp = numberArray[i];
            numberArray[i] = numberArray[i - 1];
            numberArray[i - 1] = temp;
            swaps++;
        }
    }

    return swaps;
}