#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <utility>
#include <stack>

void initializeVisited(std::vector<std::vector<bool>>&, int, int);
void initializeMaze(std::vector<std::string>&, int, int);
bool checkNeighbors(std::vector<std::string>&, std::vector<std::vector<bool>>&, const char&, const int&, const int&, std::vector<std::pair<int,int>>&);
std::string getPath(std::vector<std::string>&, const char&, int, int);


int main(int argc, char* argv[])
{
    int height{0};
    int width{0};
    std::string results;
    std::vector<std::string> maze;

    std::cin >> width >> height;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    initializeMaze(maze, height, width);
    
    results += getPath(maze, 'A', height, width);
    // results += getPath(maze, 'B', height, width);
    // results += getPath(maze, 'C', height, width); 

    std::cout << results << std::endl;

    return 0;
}

std::string getPath(std::vector<std::string>& maze, const char& target, int height, int width)
{
    std::stack<std::pair<int, int>> nodes
    std::vector<std::vector<bool>> visited;
    std::vector<std::pair<int,int>> openPaths;
    initializeVisited(visited, height, width);
    int currentRow{1};
    int currentCol{1};
    maze[currentRow][currentCol] = '*';

    checkNeighbors(maze, visited, target, currentRow, currentCol, openPaths);

    while (!openPaths.empty())
    {
        visited[currentRow][currentCol] = true;
        currentRow = openPaths.back().first;
        currentCol = openPaths.back().second;
        openPaths.pop_back();
        nodes.insert(std::make_pair(currentRow, currentCol));


        // std::cout << currentRow << ", " << currentCol;
        if (maze[currentRow][currentCol] == target)
        {
            std::cout << target << " found at " << currentRow << ", " << currentCol << std::endl;

            for (auto row: maze)
            {
                std::cout << row << std::endl;
            }
            std::cout << std::endl;
        
            break;
        }
        maze[currentRow][currentCol] = '*';
        if(checkNeighbors(maze, visited, target, currentRow, currentCol, openPaths))
        {

        }
        else
        {
            
        }
        

    }

    // for (auto node: nodes)
    // {
    //     std::cout << node.first.first << " " << node.first.second << std::endl;
    // }
    
    return "Found it ";

}

bool checkNeighbors(std::vector<std::string>& maze, std::vector<std::vector<bool>>& visited, const char& target, const int& currentRow, const int& currentCol, 
                    std::vector<std::pair<int,int>>& openPaths)
{
    int counter{0}:

    if (maze[currentRow-1][currentCol] == '1' || maze[currentRow-1][currentCol] == target && visited[currentRow-1][currentCol] == false)
    {
        openPaths.emplace_back(std::make_pair(currentRow-1, currentCol));
        counter++;
    }
    if (maze[currentRow][currentCol-1] == '1' || maze[currentRow][currentCol-1] == target && visited[currentRow][currentCol-1] == false)
    {
        openPaths.emplace_back(std::make_pair(currentRow, currentCol-1));
        counter++;
    }
    if (maze[currentRow][currentCol+1] == '1' ||  maze[currentRow][currentCol+1] == target && visited[currentRow][currentCol+1] == false)
    {
        openPaths.emplace_back(std::make_pair(currentRow, currentCol+1));
        counter++;
    }
    if (maze[currentRow+1][currentCol] == '1' || maze[currentRow + 1][currentCol] == target && visited[currentRow+1][currentCol] == false)
    {
        openPaths.emplace_back(std::make_pair(currentRow+1, currentCol));
        counter++;
    }

    if (counter > 0) return true;

    return false;
}

void initializeVisited(std::vector<std::vector<bool>>& maze, int height, int width)
{
    std::vector<bool> booleanRow(width+2, false);
    for (int j = 0; j < height+2; ++j)
    {
        maze.emplace_back(booleanRow);
    }
}

void initializeMaze(std::vector<std::string>& maze, int rows, int cols)
{
    std::string row;
    std::string filler(cols + 2, '0');
    
    maze.emplace_back(filler);
    for (int i = 0; i < rows; ++i)
    {
        std::getline(std::cin, row);
        maze.emplace_back('0' + row + '0');
    }
    maze.emplace_back(filler);

    //Place A, B, C in the grid
    maze[1][cols] = 'A';
    maze[rows][1] = 'B';
    maze[rows][cols] = 'C';
}