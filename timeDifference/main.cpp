#include <iostream>
#include <vector>
#include <string>

std::string getDifference(const int&, const int&, const int&, const int&, const int&, const int&, const int&, const int&);
unsigned long toSeconds(const int&, const int&, const int&, const int&);
std::string secondsToString(unsigned long);

int main(int argc, char* argv[])
{
    int numberOfCases{0};
    int days1{0};
    int days2{0};
    int hours1{0};
    int hours2{0};
    int minutes1{0};
    int minutes2{0};
    int seconds1{0};
    int seconds2{0};

    std::vector<std::string> timeDifferences;

    
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

    std::cout << "Please enter the the start and the end time (e.g (departure) day hour minute second (arrival) day hour minute second:" << std::endl;
  
    for (int i=0; i <numberOfCases; ++i){
        std::cin >> days1 >> hours1 >> minutes1 >> seconds1 >> days2 >> hours2 >> minutes2 >> seconds2;
        timeDifferences.push_back(getDifference(days1, hours1, minutes1, seconds1, days2, hours2, minutes2, seconds2));
    }

    for (auto difference: timeDifferences){
        std::cout << difference << " ";
    }

    std::cout << std::endl;

    return 0;
}

std::string getDifference(const int& days1, const int& hours1, const int& minutes1, const int& seconds1, const int& days2, const int& hours2, const int& minutes2, const int& seconds2)
{
    unsigned long departure = toSeconds(days1, hours1, minutes1, seconds1);
    unsigned long arrival = toSeconds(days2, hours2, minutes2, seconds2);

    unsigned long difference = arrival-departure;

    return secondsToString(difference);
}

unsigned long toSeconds(const int& days, const int& hours, const int& minutes, const int& seconds)
{
    return days*86400 + hours*3600 + minutes*60 + seconds;
}

std::string secondsToString(unsigned long seconds)
{
    int days = seconds/86400;
    seconds %= 86400;
    int hours = seconds/3600;
    seconds %= 3600;
    int minutes = seconds/60;
    seconds %= 60;

    return "(" + std::to_string(days) + " " + std::to_string(hours) + " " + std::to_string(minutes) + " " + std::to_string(seconds) +")";
}