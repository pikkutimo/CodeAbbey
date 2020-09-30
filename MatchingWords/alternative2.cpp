#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

class Cave {
private:
    std::vector<std::string>array;
    std::vector<std::string>trueArr;
public:
    Cave() {
        std::string string;
        while (string != "end") {
            std::cin >> string;
            array.push_back(string);
        }
    }
    void sort() {
        while (true) {
            bool sorting = 0;
            for (int i = 0; i < (array.size()-1); i++) {
                if (array[i] > array[i + 1]) {
                    std::swap(array[i], array[i + 1]);
                    ++sorting;
                }
            }
            if (!sorting) {
                break;
            }
        }
    }
    void deleting() {
        int dob = 0;
        for (int i = 0; i < (array.size()-1); i++) {
            if (array[i] == array[i + 1]) 
                trueArr.push_back(array[i]);
            while (array[i] == array[i + 1]) {
                ++i;
            }
        }
    }
    void print() {
        for (auto &kek : trueArr) {
            std::cout << kek << ' ';
        }
        std::cout << std::endl;
    }
};

int main()
{
    Cave tresure;
    tresure.sort();
    tresure.deleting();
    tresure.print();
    return 0;
}