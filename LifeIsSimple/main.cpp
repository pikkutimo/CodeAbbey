#include <iostream>
#include <string>

void fillArray(char[][17]);
void printArray(char[][17], int&);
void checkArray(char[][17]);
void updateArray(char[][17]);

int main(int argc, char* argv[])
{
    constexpr int start{5};
    constexpr int rowEnd{10};
    constexpr int columnEnd{12};
    int organism{0};
    int counter{0};
    char grid[14][17];
    char input;
    std::string verdict{""};

    fillArray(grid);

    for (int i = start; i < rowEnd; ++i)
    {
        for (int j= start; j < columnEnd; ++j)
        {
            std::cin >> input;
            if (input == 'X')
            {
                grid[i][j] = input;
            }
        }
    }

    printArray(grid, organism);
    
    while(counter != 5)
    {
        organism = 0;
        checkArray(grid);
        updateArray(grid);
        printArray(grid, organism);
        counter++;
        verdict = verdict + std::to_string(organism) + " ";
    }

    std::cout << "\n" << verdict << std::endl;

    return 0;
}

void fillArray(char grid[][17])
{
    for (int i = 0; i < 14; ++i)
    {
        for (int j= 0; j < 16; ++j)
        {
            grid[i][j] = '-';
        }
    }
}

void printArray(char grid[][17], int& organism)
{
    for (int i = 0; i < 14; ++i)
    {
        for (int j= 0; j < 16; ++j)
        {
            std::cout << grid[i][j] << " ";
            if (grid[i][j] == 'X') organism++;
        }
        std::cout << std::endl;
    }
}

void checkArray(char grid[][17])
{
    for (int i = 0; i < 14; ++i)
    {
        for (int j= 0; j < 16; ++j)
        {
            int neigbour{0};
            
            if (grid[i-1][j-1] == 'X' || grid[i-1][j-1] == 'x') neigbour++;
            if (grid[i-1][j] == 'X' || grid[i-1][j] == 'x') neigbour++;
            if (grid[i-1][j+1] == 'X' ||grid[i-1][j+1] == 'x') neigbour++;
            if (grid[i][j-1] == 'X' || grid[i][j-1] == 'x') neigbour++;
            if (grid[i][j+1] == 'X' || grid[i][j+1] == 'x') neigbour++;
            if (grid[i+1][j-1] == 'X' || grid[i+1][j-1] == 'x') neigbour++;
            if (grid[i+1][j] == 'X' || grid[i+1][j] == 'X') neigbour++;
            if (grid[i+1][j+1] == 'X' || grid[i+1][j+1] == 'X') neigbour++;
            
            if (grid[i][j] == 'X')
            {
                if (neigbour < 2 || neigbour > 3) grid[i][j] = 'x';
            }
            else if (grid[i][j] == '-')
            {
                if (neigbour == 3) grid[i][j] = '.';
            }
        }
    }

}

void updateArray(char grid[][17])
{
    for (int i = 0; i < 14; ++i)
    {
        for (int j= 0; j < 16; ++j)
        {
            if (grid[i][j] == '.') grid[i][j] = 'X';
            else if (grid[i][j] == 'x') grid[i][j] = '-';
        }
    }
}