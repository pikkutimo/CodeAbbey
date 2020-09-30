#include <iostream>
#include <vector>

void populateVector(const int&, std::vector<int>&);

int main(int argc, char* argv[])
{
    int numberOfPeople{0};
    int step{0};
    int counter{1};
    std::vector<int> peopleArray;

    std::cout << "Please, input the number of people and the step separated by a space (e.g. 19 3): ";
    std::cin >> numberOfPeople >> step;

    populateVector(numberOfPeople, peopleArray);

    while(peopleArray.size() != 1)
    {
        for (auto it = peopleArray.begin(); it != peopleArray.end(); )
        {
            if(counter == step)
            {
                peopleArray.erase(it);
                counter = 1;
            }
            else
            {
                ++it;
                ++counter;
            }
        }
    }

    for (int value : peopleArray)
    {
        std::cout << value << std::endl;
    }


    return 0;
}

void populateVector(const int& numberOfPeople, std::vector<int>& arrayOfPeople)
{
    for (auto i = 1; i <= numberOfPeople; ++i)
    {
        arrayOfPeople.emplace_back(i);
    }
}