//
//  poj1611.cpp
//  poj3
//
//  Created by zhou on 13-6-8.
//  Copyright (c) 2013年 zhou. All rights reserved.
//

#include <iostream>
const int MAXSIZE = 60000;

int p[MAXSIZE];
int size[MAXSIZE];


int get_p(int j){
    //得到根节点，并且路径压缩，使树高度变短
    if(p[j] != j ){
        p[j] = get_p(p[j]);
    }
    return p[j];
}

void get_union(int num1, int num2){
    //将size小的加到size大的上面，更新size
    int i,j;
    i = get_p(num1);
    j = get_p(num2);
    if(i == j){return;}
    
    if (size[i]<size[j]) {
        p[i] = j;
        size[j] += size[i];
        size[i] = 1;
    }
    else{
        p[j] = i;
        size[i] += size[j];
        size[j] = 1;
    }
    
}

int main(){
    
    
    int rel_num;
    int m, n;
    int testcase = 0;
    scanf("%d%d",&n,&m);
    while(m!=0 || n!= 0){
        testcase++;
        rel_num = n;
        for(int i=1; i<=n; i++){
            p[i] = -1;
            size[i] = 1;
        }
        
        for(int i=0; i<m; i++){
            int rel_i, rel_j;
            scanf("%d%d", &rel_i, &rel_j);
            if (p[rel_i] == -1){
                if(p[rel_j] == -1){
                    p[rel_i] = rel_i;
                    p[rel_j] = rel_i;
                    size[rel_i]++;
                }
                else{
                    p[rel_i] = rel_j;
                     size[rel_j]++;
                }
                
            }
            else {
                if(p[rel_j] == -1){
                    p[rel_j] = rel_i;
                    size[rel_i]++;
                }
                else{
                    if(get_p(rel_i) == get_p(rel_j)){
                        continue;
                    }
                    
                    get_union(rel_i, rel_j);
                }
                
            }
            rel_num--;
            
            if(rel_i == rel_j)
                rel_num++;
        }
            
        printf("Case %d: %d\n", testcase, rel_num);
        
        scanf("%d%d",&n,&m);
        
    }
    
    return 0;
}