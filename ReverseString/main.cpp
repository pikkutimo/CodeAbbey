#include <iostream>
#include <cstring>
#include <stdio.h>

int main(int argc, char* argv[])
{
    char input[100];
    char temp;
    int lenght{0};
    int i = 0;

    std::cout << "Please, give your string: ";
    std::cin.getline(input, 100);
    lenght = strlen(input);
    int j = lenght - i - 1;

    do{
        temp = input[i];
        input[i] = input[j];
        input[j] = temp;
        ++i;
        --j;
    } while (i < j);

    std::cout << input << std::endl;
   
    return 0;
}