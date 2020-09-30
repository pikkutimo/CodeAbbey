#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <utility>
#include <stack>

void initializeVisited(std::vector<std::vector<bool>>&, int, int);
void initializeMaze(std::vector<std::string>&, int, int);
bool checkNeighbors(std::vector<std::string>&, std::vector<std::vector<bool>>&, const char&, const int&, const int&, int&, int&);
std::string getPath(std::vector<std::string>&, const char&, int, int);
std::string convertPath(std::stack<int>&, std::stack<int>&);
std::string shortenPath(std::string&);


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
    results += getPath(maze, 'B', height, width);
    results += getPath(maze, 'C', height, width); 

    std::cout << results << std::endl;

    return 0;
}

std::string getPath(std::vector<std::string>& maze, const char& target, int height, int width)
{
    std::stack<int> rows;
    std::stack<int> columns;
    std::vector<std::vector<bool>> visited;
    int currentRow{1};
    int currentCol{1};
    int nextRow;
    int nextColumn;

    initializeVisited(visited, height, width);

    while(maze[currentRow][currentCol] != target)
    {
        // std::cout << currentRow << "," << currentCol << std::endl;
        // Mark the coordinates visited and add them to the stack
        visited[currentRow][currentCol] = true;
        rows.push(currentRow);
        columns.push(currentCol);

        // Check if there are ways forward, if not go back in stack until you find a way forward
        if(checkNeighbors(maze, visited, target, currentRow, currentCol, nextRow, nextColumn))
        {
            // std::cout << "Way forward " << nextRow << "," << nextColumn << std::endl;
            currentRow = nextRow;
            currentCol = nextColumn;
        }
        else
        {
            while (checkNeighbors(maze, visited, target, currentRow, currentCol, nextRow, nextColumn) == false)
            {
                // std::cout << "No viable way forward found." << std::endl;
                // std::cout << "Let's remove from rows " << rows.top();
                // std::cout << " and from cols " << columns.top() << std::endl;
                rows.pop();
                columns.pop();
                // std::cout << "Now the top ones are " << rows.top() << "," << columns.top() << std::endl;

                currentRow = rows.top();
                currentCol = columns.top();
            }   

            // std::cout << "Way forward " << nextRow << "," << nextColumn << std::endl;
            currentRow = nextRow;
            currentCol = nextColumn;
        }
        // std::cin.get();
    }
    
    rows.push(currentRow);
    columns.push(currentCol);

    return convertPath(rows, columns);

}

std::string convertPath(std::stack<int>& rows, std::stack<int>& cols)
{
    int row;
    int col;
    int previousRow = rows.top();
    int previousCol = cols.top();
    rows.pop();
    cols.pop();
    std::string path;

    while(!rows.empty())
    {
        row = rows.top();
        col = cols.top();
        rows.pop();
        cols.pop();
        if (row == previousRow && col != previousCol)
        {
            if (col < previousCol)
                path += "L";
            else
                path += "R";
        }
        else if (col == previousCol && row != previousRow)
        {
            if (row < previousRow)
                path += "U";
            else
                path += "D";
        }

        previousRow = row;
        previousCol = col;
    }

    return shortenPath(path);

}

std::string shortenPath(std::string& path)
{
    int count{1};
    char previous = path[0];
    std::string shortPath;

    for (int i = 1; i < path.length(); ++i)
    {
        if (path[i] == previous) count++;
        else
        {
            shortPath = shortPath + std::to_string(count) + previous;
            count = 1;
        }

        previous = path[i];
        
    }

    shortPath = shortPath + std::to_string(count) + previous + " ";    

    return shortPath;
}

bool checkNeighbors(std::vector<std::string>& maze, std::vector<std::vector<bool>>& visited, const char& target, 
            const int& currentRow, const int& currentCol, int& nextRow, int& nextColumn)
{
    int counter{0};

    if ((maze[currentRow-1][currentCol] == '1' || maze[currentRow-1][currentCol] == target) && visited[currentRow-1][currentCol] == false)
    {
        nextRow = currentRow-1;
        nextColumn = currentCol;
        counter++;
    }
    if ((maze[currentRow][currentCol-1] == '1' || maze[currentRow][currentCol-1] == target) && visited[currentRow][currentCol-1] == false)
    {
        nextRow = currentRow;
        nextColumn = currentCol - 1;
        counter++;
    }
    if ((maze[currentRow][currentCol+1] == '1' ||  maze[currentRow][currentCol+1] == target) && visited[currentRow][currentCol+1] == false)
    {
        nextRow = currentRow;
        nextColumn = currentCol + 1;
        counter++;
    }
    if ((maze[currentRow+1][currentCol] == '1' || maze[currentRow + 1][currentCol] == target) && visited[currentRow+1][currentCol] == false)
    {
        nextRow = currentRow + 1;
        nextColumn = currentCol;
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