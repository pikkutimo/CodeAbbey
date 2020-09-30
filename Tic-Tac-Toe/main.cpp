#include <iostream>
#include <vector>

constexpr int numberOfMoves{9};
constexpr int x{3};
constexpr int y{3};
void playGame(const std::vector<int>&, std::vector<int>&);
bool hasEnded(const int[][y]);

int main(int argc, char* argv[])
{
    int numberOfGames{0};
    int move{0};
    std::vector<int> gameMoves;
    std::vector<int> movesToWin;

    std::cin >> numberOfGames;

    for (int i = 0; i < numberOfGames; ++i) 
    {
        for (int j = 0; j < numberOfMoves; ++j)
        {
            std::cin >> move;
            gameMoves.emplace_back(move);
        }
        playGame(gameMoves, movesToWin);
        gameMoves.clear();
    }

    for (auto moves: movesToWin)
    {
        std::cout << moves << " ";
    }

    std::cout << std::endl;

    return 0;
}

void playGame(const std::vector<int>& gameMoves, std::vector<int>& movesToWin)
{
    int gameGrid[x][y] = {0,0,0,0,0,0,0,0,0};
    int row{0};
    int column{0};
    bool isWin{false};

    for (int i = 0; i < numberOfMoves; ++i)
    {
        if (gameMoves[i] < 4)
        {
            row = 0;
            column = gameMoves[i] - 1;
        }
        else if (gameMoves[i] < 7)
        {
            row = 1;
            column = gameMoves[i] - 4;
        }
        else
        {
            row = 2;
            column = gameMoves[i] - 7;
        }

        if (i % 2 == 0)
        {
            gameGrid[row][column] = 4;
        }
        else
        {
            gameGrid[row][column] = 1;
        }

        if (hasEnded(gameGrid))
        {
            movesToWin.emplace_back(i+1);
            isWin = true;
            break;
        }
    }

    if (isWin == false)
    {
        movesToWin.emplace_back(0);
    }
}

bool hasEnded(const int gameGrid[][y])
{
    if (gameGrid[0][0] +gameGrid[0][1] + gameGrid[0][2] == 3 || gameGrid[0][0] +gameGrid[0][1] + gameGrid[0][2] == 12) return true;
    else if (gameGrid[1][0] +gameGrid[1][1] + gameGrid[1][2] == 3 || gameGrid[1][0] +gameGrid[1][1] + gameGrid[1][2] == 12) return true;
    else if (gameGrid[2][0] +gameGrid[2][1] + gameGrid[2][2] == 3 || gameGrid[2][0] +gameGrid[2][1] + gameGrid[2][2] == 12) return true;
    else if (gameGrid[0][0] +gameGrid[1][0] + gameGrid[2][0] == 3 || gameGrid[0][0] +gameGrid[1][0] + gameGrid[2][0] == 12) return true;
    else if (gameGrid[0][1] +gameGrid[1][1] + gameGrid[2][1] == 3 || gameGrid[0][1] +gameGrid[1][1] + gameGrid[2][1] == 12) return true;
    else if (gameGrid[0][2] +gameGrid[1][2] + gameGrid[2][2] == 3 || gameGrid[0][2] +gameGrid[1][2] + gameGrid[2][2] == 12) return true;
    else if (gameGrid[0][0] +gameGrid[1][1] + gameGrid[2][2] == 3 || gameGrid[0][0] +gameGrid[1][1] + gameGrid[2][2] == 12) return true;
    else if (gameGrid[0][2] +gameGrid[1][1] + gameGrid[2][0] == 3 || gameGrid[0][2] +gameGrid[1][1] + gameGrid[2][0] == 12) return true;

    return false;
}