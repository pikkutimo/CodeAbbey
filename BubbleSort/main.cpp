#include <iostream>

int main(int argc, char* argv[])
{
    int numberOfPasses{0};
    int swapsMade;
    int totalSwaps{0};
    int temp{0};
    int numberOfElements{0};
    int arrayOfElements[100] = {0};

    std::cin >> numberOfElements;

    for (auto i = 0; i < numberOfElements; ++i)
    {
        std::cin >> temp;
        arrayOfElements[i] = temp;
    }

    while(true)
    {
        swapsMade = 0;

        for (int i = 1; i < numberOfElements; ++i)
        {
            if (arrayOfElements[i] < arrayOfElements[i-1])
            {
                temp = arrayOfElements[i];
                arrayOfElements[i] = arrayOfElements[i-1];
                arrayOfElements[i-1] = temp;
                swapsMade++;
            }
        }

        totalSwaps += swapsMade;
        numberOfPasses++;

        if (swapsMade == 0) break;
    }

    std::cout << numberOfPasses << " " << totalSwaps << std::endl;
    
    return 0;
}