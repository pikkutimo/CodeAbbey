#include <iostream>
#include <string>
#include <cmath>

int main(int argc, char* argv[])
{
    int numberOfTriangles{0};
    std::string triangles{""};
    int legA{0};
    int legB{0};
    int legC{0};
    int hypotenuse{0};

    std::cin >> numberOfTriangles;

    for (int i = 0; i < numberOfTriangles; ++i)
    {
        std::cin >> legA >> legB >> legC;

        hypotenuse = sqrt(legA*legA + legB*legB);
        if (legC == hypotenuse)
        {
            triangles += "R "; 
        }
        else if (legC > hypotenuse)
        {
            triangles += "O ";
        }
        else
        {
            triangles += "A ";
        }
    }

    std::cout << triangles << std::endl;
    
    return 0;
}