//
//  poj1604.cpp
//  poj
//
//  Created by zhou on 13-6-25.
//  Copyright (c) 2013年 zhou. All rights reserved.
//

#include <iostream>

int main(){
    
    
    int n;
while(scanf("%d", &n)){
    long long int total=1;
    int five_sum = 0;
    for (int i=5; i<=n; i+=5) {
        int temp = i;
        while (temp%10 == 0) {
            temp = temp / 10;
        }
        while ((temp % 5) == 0) {
            temp = temp / 5;
            five_sum += 1;
        }
        total *= temp%10;
        if(total > 100000000){
            total = total % 10;
        }
    }
    
    for(int i=1; i<=n; i++){
        if(i % 5 == 0){
            continue;
        }
        int temp = i;
        
        while(five_sum != 0 && temp % 2 == 0){
            temp /= 2;
            five_sum--;
        }
        
        total *= (temp%10);
        if(total > 1000000000){
            total = total % 10;
        }
    }
    
    printf("%5.d -> %lld\n", n,total%10);
}
    
    return  0;
}