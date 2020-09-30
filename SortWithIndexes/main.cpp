#include <iostream>

void bubbleSort(const int&, int[]);
void getInitialIndex(const int&, const int[], const int[]);

int main(int argc, char* argv[])
{
    int arraySize{0};

    std::cout << "Please, enter the number of elements for the array: ";
    std::cin >> arraySize;

    int numbers[arraySize] = {0};
    int numberIndex[arraySize] = {0};

    std::cout << "Enter the elements separated by a space (e.g. 1 2 3):" << std::endl;
    for (auto i = 0; i < arraySize; ++i)
    {
        std::cin >> numbers[i];
        numberIndex[i] = numbers[i];
    }

    bubbleSort(arraySize, numbers);
    getInitialIndex(arraySize, numbers, numberIndex);
    std::cout << std::endl;

    return 0;
}

void bubbleSort(const int& size, int numbers[])
{
    int temp{0};
    int numberOfSwaps;

    while(true){
        numberOfSwaps = 0;
        for (auto i = 1; i < size; ++i)
        {
            if (numbers[i] < numbers[i-1]){
                temp = numbers[i];
                numbers[i] = numbers[i-1];
                numbers[i-1] = temp;
                numberOfSwaps++;
            }
        }

        if(numberOfSwaps == 0) break;
    }
}

void getInitialIndex(const int& size, const int numbers[], const int numberIndex[])
{
    for(auto i = 0; i < size; ++i)
    {
        for (auto j = 0; j < size; ++j)
        {
            if(numbers[i] == numberIndex[j])
            {
                std::cout << j + 1 << " ";
                break;
            }
        }
    }
}