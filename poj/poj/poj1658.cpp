//
//  poj1658.cpp
//  poj
//
//  Created by zhou on 13-6-15.
//  Copyright (c) 2013年 zhou. All rights reserved.
//

#include <iostream>

int main(){
    
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
    
        int n1, n2, n3, n4;
        scanf("%d%d%d%d", &n1, &n2, &n3, &n4);
        printf("%d %d %d %d ", n1, n2, n3, n4);
        if(n2/n1 == n3/n2){
            printf("%d\n", n4/n3*n4);
        }
        else{
            printf("%d\n", n4-n3+n4);
        }
        
    }
    
    
    
    return 0;
}