//
//  poj1656.cpp
//  poj
//
//  Created by zhou on 13-6-15.
//  Copyright (c) 2013年 zhou. All rights reserved.
//


#include <iostream>
#include <string>

using namespace std;


const int MAXSIZE = 100;
int x, y, l;


int board[MAXSIZE+1][MAXSIZE+1];

void paint(int mode){
    for(int i=x; i<x+l; i++){
        for (int j=y; j<y+l; j++) {
            board[i][j] = mode;
            
        }
    }


}

void print_data(){
    int sum = 0;
    for(int i=x; i<x+l; i++){
        for (int j=y; j<y+l; j++) {
            if(board[i][j] == 1){
                sum++;
            }
        }
    }
    cout<<sum<<endl;
}


int main(){
    int command_num;
    cin>>command_num;
    memset(board, 0, sizeof(int)*(MAXSIZE+1)*(MAXSIZE+1));
    for(int i=0; i<command_num; i++){
        
        string command;
        cin>>command;
        
        cin>>x>>y>>l;
        
        switch (command[0]) {
            case 'B':
                paint(1);
                break;
            case 'W':
                paint(0);
                break;
            case 'T':
                print_data();
                break;
                
            default:
                break;
        }
    }
    
    
    return 0;
}
