//
//  poj1218.cpp
//  poj
//
//  Created by zhou on 13-6-14.
//  Copyright (c) 2013年 zhou. All rights reserved.
//

#include <iostream>

int main(){
    
    int line_num;
    scanf("%d", &line_num);
    
    for(int i=0; i<line_num; i++){
        int n;
        scanf("%d", &n);
        int sum_escape =0;
        for(int j=1; j<=n; j++){
            bool pass=false;
            int k=1;
            for(; k<=n; k++){
                if(j%k == 0){
                    pass = !pass;
                }
            }
            if(pass){
                sum_escape++;
            }
        }
        printf("%d\n", sum_escape);
    }
    
    
    
    return 0;
}
