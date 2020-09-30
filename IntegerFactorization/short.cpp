#include <iostream>

using namespace std;

int main (){
int a;
cin>>a;

long int x;
for(int i=0; i<a; i++){
    cin>>x;
for(int z=2;z<=x;z++) {
       if(x%z==0) {
        cout<<z<<"*";
          x/=z;
          z--;
       }
}
cout<<" ";
}
return 0;
}