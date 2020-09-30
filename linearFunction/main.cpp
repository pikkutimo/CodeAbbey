#include <iostream>
#include <vector>
#include <string>

std::string getConstants(const int&, const int&, const int&, const int&);

int main(int argc, char* argv[])
{
    int numberOfCases{0};
    int x1{0};
    int x2{0};
    int y1{0};
    int y2{0};

    std::vector<std::string> equationConstants;
    
    bool notValid{true};

    std::cout << "Please, enter the number of test-cases:\n";
    while(notValid)
    {
        std::cin >> numberOfCases;
        if(std::cin.fail()){
            std::cout << "Please enter integer value." << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
        else
        {
            notValid = false;
        }
        
    }

    std::cout << "Please enter the two first x values and their corresponding y values(e.g. x1 y1 x2 y2):" << std::endl;
  
    for (int i=0; i <numberOfCases; ++i){
        std::cin >> x1 >> y1 >> x2 >> y2;
        equationConstants.push_back(getConstants(x1, y1, x2, y2));
    }

    for (auto constants: equationConstants){
        std::cout << constants << " ";
    }

    std::cout << std::endl;

    return 0;
}

std::string getConstants(const int& x1, const int& y1, const int& x2, const int& y2)
{
    int a = (y1-y2)/(x1-x2);
    int b = y1 - (a*x1);
    return "(" + std::to_string(a) + " " + std::to_string(b) + ")";
}