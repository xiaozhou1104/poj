//
//  poj1045.cpp
//  poj
//
//  Created by zhou on 13-6-15.
//  Copyright (c) 2013年 zhou. All rights reserved.
//

#include <iostream>
#include <math.h>

int main(){
    
    int n;
    double vs, r, c;
    scanf("%lf%lf%lf%d", &vs, &r, &c, &n);
    
    double w;
    double result;
    for(int i=0; i<n; i++){
        scanf("%lf", &w);
        result = vs * cos(atan2(1, w*r*c));
        printf("%.3f\n", result);
    }
    
    
}