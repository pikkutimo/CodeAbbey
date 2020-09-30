#include <stdio.h>

unsigned char flags (unsigned char x){
    unsigned char res = 0;
    while (x){
        if (x%2){
            res++;
        }
        x>>=1;
    }
    return res;
}

int main(void){
    unsigned char sym = 0;
    while (sym != '.'){
       scanf("%u",&sym);
       if (!(flags(sym)%2)){
           if (sym/(1<<7)){
                sym^=(1<<7);
           }
           printf("%c",sym);
       }
    }
    return 0;
}