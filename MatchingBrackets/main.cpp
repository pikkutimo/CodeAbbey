#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

bool matchBrackets(std::string&);

int main(int argc, char* argv[])
{
    int numberOfTestCases{0};
    std::vector<bool> charSequences;
    std::string input;

    std::cout << "Please, input the number of test-cases: ";
    std::getline(std::cin, input);

    numberOfTestCases = std::stoi(input);

    for (auto i = 0; i < numberOfTestCases; ++i)
    {
        std::getline(std::cin, input);
        charSequences.push_back(matchBrackets(input));
    }

    for (auto judgement: charSequences){
        std::cout << judgement << " ";
    }

    std::cout << std::endl;


    return 0;
}

bool matchBrackets(std::string& stringToMatch)
{
    std::string toMatch{"(){}[]<>"};

    stringToMatch.erase(std::remove_if(stringToMatch.begin(), stringToMatch.end(),
                        [&toMatch](const char& c) {
                            return toMatch.find(c) == std::string::npos;
                        }), stringToMatch.end());

    int round{0};
    int square{0};
    int curly{0};
    int angle{0};
    char charToSearch;
    char previousChar;

    // std::cout << stringToMatch << std::endl;

    for (auto it=stringToMatch.begin(); it != stringToMatch.end(); ++it)
    {
        previousChar = *it;
        if (*it == '('){
            charToSearch = ')';
            round +=1;
        }
        else if (*it == '['){
            charToSearch = ']';
            square +=1;
        }
        else if (*it == '{'){
            charToSearch = '}';
            curly +=1;
        }
        else if (*it == '<'){
            charToSearch = '>';
            angle +=1;
        }
        else if (*it == ')' || *it == ']' || *it == '>' || *it == '}')
        {
            return false;
        }

        for (auto itr = it+1; itr != stringToMatch.end(); ++itr)
        {
            if (*itr == '(') round += 1;
            else if (*itr == '[') square += 1;
            else if (*itr == '{') curly += 1;
            else if (*itr == '<') angle += 1;
            else if (*itr == ')' && (previousChar == '<' ||previousChar == '{' || previousChar == '[' || round==0)) return false;
            else if (*itr == ')') round -= 1;
            else if (*itr == ']' && (previousChar == '<' ||previousChar == '{' || previousChar == '(' || square==0)) return false;
            else if (*itr == ']') square -= 1;
            else if (*itr == '}' && (previousChar == '<' ||previousChar == '[' || previousChar == '(' || curly==0)) return false;
            else if (*itr == '}') curly -= 1;
            else if (*itr == '>' && (previousChar == '[' ||previousChar == '{' || previousChar == '(') || angle==0) return false;
            else if (*itr == '>') angle -= 1;

            if (*itr == charToSearch && round == 0 && angle == 0 && curly == 0 && square == 0){
                it = itr;
                break;
            }
            previousChar = *itr;
        }
        if (round != 0 || angle != 0 || curly != 0 || square != 0) return false;

    }

    return true;
    
}
