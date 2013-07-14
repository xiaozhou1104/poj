//
//  poj1517.cpp
//  poj
//
//  Created by zhou on 13-6-14.
//  Copyright (c) 2013年 zhou. All rights reserved.
//

#include <iostream>
using namespace std;



int main(){
    
    printf("n e\n");
    printf("- -----------\n");
    int n = 9;
    double sum = 0;
    int cal = 1;
    for(int i=0; i<=n; i++){
        if(i != 0){
            cal *= i;
        }
        sum += (double)1/cal;
        if(i == 0 || i == 1){
            printf("%d %.0f\n", i, sum);
        }
        else if(i == 2){
            printf("%d %.1f\n", i, sum);
        }
        else {
            printf("%d %.9f\n", i, sum);
        }
    }
    
    return 0;
}
