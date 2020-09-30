Home
Problems
Volumes
Ranking
Forum
Help
Mess
random task user's settings user's profile logout14:35:04
Search...
Viewing Solution
Task: Prime Numbers Generation (#61)
User: al.semakin
Date: May 31 2020 13:49
Language: C/C++	
Like this code
#include <iostream>
#include <string> 
#include <sstream>
#include <vector>
#include <fstream> 


template <typename T>
void PrintVec(const std::vector<T>& v ){
    for(const auto&i:v)
        std::cout << i << ' ';
    std::cout << std::endl;
}

std::vector <std::string> split(const std::string & s, char delimeter = ' '){
    std::stringstream ss(s);
    std::string item;
    std::vector<std::string> tokens;
    while (getline(ss, item, delimeter)){
        tokens.push_back(item);
    }
    return tokens;
}

void ReadDataFromFile(const std::string FileName,
                        std::vector<std::string>& v)
{
    std::ifstream fin(FileName);
    std::string line;

    if(fin){
        std::getline(fin, line);
        while(std::getline(fin, line)){
            v.push_back(line);
        }
    }
    else{ 
        std::cout<< "\tError. File can't open." << std::endl;
    }
}



std::vector<unsigned int> prime;

void eratosfen(unsigned int limit)
{
    unsigned int* bitmap = (unsigned int*) calloc(limit / 64 + ((limit & 63) ? 1 : 0), sizeof(unsigned int));
    //printf("2 3 ");
    prime.push_back(2);
    prime.push_back(3);
    unsigned int max_prime = 3;
    bool need_fill = true;
    while(need_fill) {
        unsigned int step = max_prime << 1;
        for(unsigned int i = max_prime * max_prime; i < limit; i += step) { // Вычеркиваем кратные max_pr
            bitmap[i >> 6] |= (1 << ((i >> 1) & 31));
        }
        if(max_prime * max_prime >= limit) need_fill = false; // дальше заполнять не надо
        // вычитываем следущую порцию
        for(unsigned int i = max_prime + 2; i < limit; i += 2) {
            if((bitmap[i >> 6] & (1 << ((i >> 1) & 31))) == 0) {
                prime.push_back(i);
                //printf("%u ", i);
                if(need_fill) {
                    max_prime = i;
                    break;
                }
            }
        }
    }
    free(bitmap);
}

void Do(std::string& s){
    eratosfen(2750132);
    std::vector<std::string> v = split(s);
    for(auto&i:v)
        std::cout << prime[stoi(i)-1] << ' ';
}


int main(){
    std::string FileName = "input.txt";
    std::vector<std::string> v;
    ReadDataFromFile(FileName, v);
    for(auto&i:v)
        Do(i);
    std::cout << '\n';

}

© 2013-2020 by Rodion Gorkovenko
with the help of You AllContacts and Support
Issues and IdeasPrivacy Policy