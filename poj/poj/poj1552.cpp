//
//  poj1552.cpp
//  poj
//
//  Created by zhou on 13-6-15.
//  Copyright (c) 2013年 zhou. All rights reserved.
//

#include <iostream>

int main(){
    int num[100];
   
    
    int first_n;
    scanf("%d", &first_n);
    while(first_n!=-1){
        memset(num, 0, 100*sizeof(int));
        int last_n = first_n;
        while(last_n != 0){
            num[last_n] = 1;
            scanf("%d", &last_n);
        }
        int sum = 0;
        for(int i=1; i<=49; i++){
            if(num[i] == 1 && num[i*2] == 1){
                sum++;
            }
        }
        printf("%d\n", sum);
        
        scanf("%d", &first_n);
    }
    
    
    return 0;
}
