#include <iostream>
#include <vector>

void solver(const int&, const int&);

int main(int argc, char* argv[])
{
    int rows{0};
    int columns{0};
    char inputChar;

    std::cin >> rows >> columns;

    solver(rows, columns);

    return 0;
}

void solver(const int& rows, const int& columns)
{
    char grid[rows][columns];
    char input;
    int pascalGrid[rows][columns];

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            std::cin >> input;
            grid[i][j] = input;
        }
    }

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            if (i == 0)
            {
                pascalGrid[i][j] = 1;
            }
            else if ( j == 0 )
            {
                pascalGrid[i][j] = 1;
            }
            else if (grid[i][j] == 'X')
            {
                pascalGrid[i][j] = 0;
            }
            else 
            {
                pascalGrid[i][j] = pascalGrid[i -1][j] + pascalGrid[i][j-1];
            }
        }
    }
    std::cout << pascalGrid[rows -1][columns-1] <<  std::endl;
    // for (int i = 0; i < rows; ++i)
    // {
    //     for (int j = 0; j < columns; ++j)
    //     {
    //         std::cout << pascalGrid[i][j] << " ";
    //     }

    //     std::cout << std::endl;
    // }
}