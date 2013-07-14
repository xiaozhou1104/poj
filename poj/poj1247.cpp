//
//  poj1247.cpp
//  poj
//
//  Created by zhou on 13-6-20.
//  Copyright (c) 2013年 zhou. All rights reserved.
//

#include <iostream>

int guest[30+1];

int main(){
    
    int n, sum;
    
    scanf("%d", &n);
    while (n!=0) {
        sum = 0;
        for (int i=1; i<=n; i++) {
            scanf("%d", &guest[i]);
            sum += guest[i];
        }
        
        if(sum % 2 != 0){
            printf("No equal partitioning.\n");
        }
        else {
            int local_sum=0;
            for(int j=1; j<=n; j++){
                if(local_sum < sum/2 && local_sum + guest[j] > sum/2){
                    printf("No equal partitioning.\n");
                    break;
                }
                else if(local_sum + guest[j] == sum/2){
                    printf("Sam stops at position %d and Ella stops at position %d.\n", j, j+1);
                    break;
                }
                else{
                    local_sum += guest[j];
                }
                 
            }
        }
        
        scanf("%d", &n);
    }

    
    
    
}