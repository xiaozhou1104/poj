//
//  poj1604.cpp
//  poj
//
//  Created by zhou on 13-6-25.
//  Copyright (c) 2013年 zhou. All rights reserved.
//

#include <iostream>

int a[10001];
int multi[10001];


int main(){
    
    memset(a, 0, sizeof(int)*10001);
    memset(multi, 0, sizeof(int)*10001);
    
    int n=10000;
    a[0] = 1;
    multi[0] = 1;
    for (int i=1; i<=n; i++) {
        
        if((i % 5) != 0){
            a[i] = (a[i-1] * i) % 10;
            multi[i-1] = i%10;
            
        }
        else{
            if((i % 10) == 0){
                a[i] = (a[i-1]* multi[i/10-1])%10;
                multi[i-1] = multi[i/10-1];
            }
            else if ((i % 5) == 0){
                
                a[i] = (a[i-2] * ((i-1)/2) * multi[i/5-1]) % 10;
                
                for (int k=1; k<=9; k++) {
                    if((a[i-1] * k)%10 == a[i]){
                        multi[i-1] = k;
                        break;
                    }
                }
            
            }
        }
            
    }
    
    int input_num;
    
    while(scanf("%d", &input_num)!=EOF){
        if(input_num<0 || input_num>10000){
            continue;
        }
        printf("%5d -> %d\n", input_num, a[input_num]);
    }
    
    return  0;
}