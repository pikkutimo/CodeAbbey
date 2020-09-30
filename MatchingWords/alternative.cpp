#include <iostream>
#include <string>
#include <set>

using namespace std;
using str_sz = string::size_type;

int main()
{
    string word;
    set<string> results;
    set<string> words;

    for(int i=0;i<300;i++)
    {
        cin>>word;
        if(words.count(word)==1)
            results.insert(word);
        else
            words.insert(word);
    }
    for(set<string>::iterator it=results.begin(); it!=results.end(); ++it)
    {
        cout<<*it<<" ";
    }
    return 0;
}