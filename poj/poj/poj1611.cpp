//
//  poj1611.cpp
//  poj3
//
//  Created by zhou on 13-6-8.
//  Copyright (c) 2013年 zhou. All rights reserved.
//

#include <stdio.h>
const int MAXSIZE = 30000;

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
    
    int m, n;
    scanf("%d%d",&n,&m);
    while(m!=0 || n!= 0){
        for(int i=0; i<MAXSIZE; i++){
            p[i] = -1;
            size[i] = 1;
        }
        
        for(int i=0; i<m; i++){
            int k;
            scanf("%d", &k);
            int cur_p=-1;
            int to_union = -1;
            for(int j=0; j<k; j++){
                int cur_num;
                scanf("%d",&cur_num);
                //取这一行未出现的第一个为根节点
                if(cur_p == -1){
                    if(p[cur_num] == -1){
                        //如果当前行根节点还没出现，赋值之
                        cur_p = cur_num;
                        p[cur_num] = cur_num;
                    }
                    else if(to_union == -1){
                        to_union=cur_num;
                    }
                    else{
                        get_union(cur_num, to_union);
                    }
                }
                else{
                    if(p[cur_num] == -1){
                        p[cur_num] = cur_p;
                        size[cur_p] += 1;
                    }
                    else if(to_union == -1){
                        to_union=cur_num;
                    }
                    else{
                        get_union(cur_num, to_union);
                    }
                    
                }
                
            }
            if(to_union != -1 && cur_p != -1){
                get_union(to_union, cur_p);
            }
            
        }
        
        if(p[0] == -1){
            p[0] = 0;
        }
        printf("%d\n",size[get_p(0)]);
        
        scanf("%d%d",&n,&m);
        
    }
    
    return 0;
}