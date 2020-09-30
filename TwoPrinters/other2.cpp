#include <iostream>

using namespace std;

int main(){
    int NumberTestCases; 
    unsigned int X;
    unsigned int Y;
    unsigned int N;
    unsigned long long MaxSec;
    unsigned long long MinSec;
    unsigned int CurSecX;
    unsigned int CurSecY;
    unsigned int CurN;
    
    cin >> NumberTestCases;

    for(int i=0; i<NumberTestCases; i++){
        cin >> X;
        cin >> Y;
        cin >> N;
        
        MinSec=0;
        CurSecX=0;
        CurSecY=0;
        CurN=0;
        
        if(X>Y) MaxSec = X*N;
        else MaxSec = Y*N;
        
        while(MinSec<MaxSec){
            if(CurSecX == X){
                CurSecX = 0;
                CurN++;
            }
            if(CurSecY == Y){
                CurSecY = 0;
                CurN++;
            }
            if(CurN >= N) break;
            CurSecX++;
            CurSecY++;
            MinSec++;
        }
        cout << MinSec << ' ';
    }
    return 0;
}