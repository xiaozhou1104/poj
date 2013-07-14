//
//  1316.cpp
//  poj
//
//  Created by zhou on 13-6-12.
//  Copyright (c) 2013年 zhou. All rights reserved.
//

#include <iostream>


const int MAXSIZE = 10000;

int num[MAXSIZE*2];

void d(int n){
    
    while (n < MAXSIZE) {
        int next_n = n + n/1000 + (n%1000)/100 + (n%100)/10 + n%10;
        /*
        int next_n=0;
        if(n>=1000){
            next_n = n + n/1000 + (n%1000)/100 + (n%100)/10 + n%10;
        }
        else if(n >= 100){
            next_n = n + n/100 + (n%100)/10 + n%10;
        }
        else if(n >= 10){
            next_n = n + n/10 + n%10;
        }
        else{
            next_n = n + n;
        }
         */
        
        num[next_n] = 1;
        n = next_n;
        if(num[n] == 1){
            return;
        }
        
    }
}


int main(){
    memset(num, 0, sizeof(int)*MAXSIZE);
    
    
    for(int i=1;i<MAXSIZE; i++){
        d(i);
    }
    
    for(int i=1; i<MAXSIZE; i++){
        if(num[i] == 0)
            printf("%d\n", i);
    }
    
    return 0;
}
