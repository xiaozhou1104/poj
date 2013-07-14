//
//  poj1157.cpp
//  poj
//
//  Created by zhou on 13-7-3.
//  Copyright (c) 2013年 zhou. All rights reserved.
//

#include <iostream>

int f, v;
int a[100][100];
int loc[100][100];
int p[100][100];


int max(int a, int b){
    if(a > b){
        return a;
    }
    else{
        return b;
    }
    
}

int main(){
    scanf("%d%d", &f, &v);
    
    memset(a, 0, sizeof(int));
    memset(loc, 0, sizeof(int));
    memset(p, 0, sizeof(int));
    for (int i=0; i<f; i++) {
        for (int j=0; j<v; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    if(a[0,0] > 0){
        p[0][0] = a[0][0];
        loc[0][0] = 1;
    }
    
    for (int j=1; j<v; j++) {
        if (a[0][j] > p[0][j-1] ) {
            p[0][j] = a[0][j];
            loc[0][j] = 1;
        }
        else{
            p[0][j] = p[0][j-1];
        }
    }
    
    for(int i=1; i<f; i++){
        for (int j=i; j<v; j++) {
            p[i][j] = max(p[i-1][j-1] + a[i][j], p[i][j-1]);
        }
    }
    
    printf("%d\n", p[f-1][v-1]);
    /*
    for(int i=0; i<f; i++){
        for(int j=0; j<v; j++){
            printf("%d\n", p[i][j]);
        }
    }
     */
    
    
}
