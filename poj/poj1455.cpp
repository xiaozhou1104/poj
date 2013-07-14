//
//  poj1455.cpp
//  poj
//
//  Created by zhou on 13-6-14.
//  Copyright (c) 2013年 zhou. All rights reserved.
//

#include <iostream>


int main(){
    
    int amount;
    scanf("%d", &amount);
    
    for (int i=0; i<amount; i++) {
        int n;
        scanf("%d", &n);
        if(n % 2 == 0){
            printf("%d\n", (n/2)*(n/2-1));
        }
        else{
            int b = n/2;
            printf("%d\n", b*b);
        }
    }
    
    
    
    return  0;
}
