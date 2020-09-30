#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Author: Joseph St. Pierre
//Year: 2016

typedef struct Pair{
    unsigned value;
    unsigned index;
} Pair;

int main(void){
    unsigned n;
    
    scanf("%u",&n);
    
    Pair *pairs = (Pair*)malloc(sizeof(Pair)*n);
    
    unsigned i;
    for(i = 0; i < n; i++){
        pairs[i].index = i;
        scanf("%u",&pairs[i].value);    
    }
    
    bool swap = true;
    while(swap){
        swap = false;
        
        Pair *a = &pairs[1];
        Pair *b = &pairs[0];    
        
        for(i = 1; i < n; i++){
            if(a->value < b->value){
                Pair p1 = *a;
                Pair p2 = *b;
                
                *a = p2;
                *b = p1;
                swap = true;
            }
            a++;
            b++;
        }
    }
    
    for(i = 0; i < n; i++){
        printf("%u ",pairs[i].index+1);    
    }

    return 0;    
}
