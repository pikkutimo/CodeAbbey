#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

int main(int argc, char* argv[])
{
    std::string input{""};
    std::string temp;
    std::vector<std::pair<std::string, int>> words;

    std::getline(std::cin, input);
    std::stringstream str(input);

    while (str >> temp)
    {
        bool notFound = true;
        for (auto& tuple: words)
        {
            if (tuple.first == temp)
            {
                notFound = false;
                tuple.second++;
            }
        }

        if (notFound)
        {
            words.emplace_back(std::make_pair(temp, 1));
        }
    }

    std::sort(words.begin(), words.end());

    for (auto tuple: words)
    {
        if (tuple.second > 1)
        {
            std::cout << tuple.first <<  " ";
        }
    }

    std::cout << std::endl;

    return 0;
}