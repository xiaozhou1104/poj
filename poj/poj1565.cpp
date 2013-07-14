//
//  poj1565.cpp
//  poj
//
//  Created by zhou on 13-6-20.
//  Copyright (c) 2013年 zhou. All rights reserved.
//

#include <iostream>
#include <string>

long long int multi[100];

using namespace std;

int main(){
    
    multi[0] = 1;
    for(int i=1; i<100; i++){
        multi[i] = multi[i-1] * 2;
        
        
    }
    
    
    string n;
    long long int sum, sum_digit, digit;
    
    cin>>n;
        
    while (n!= "0") {
        sum = 0;
        sum_digit = 0;
        digit = 2;
       
        int size = n.length();
        int const_size =  size;
        
        while (size != 0) {
            
            sum += (n.at(size-1)-'0') * multi[const_size - (size-1)];
            sum_digit += n.at(size-1) - '0';
            size -= 1;
        }
        
        cout<<sum-sum_digit<<endl;
        
        
        
        
        
        
        cin>>n;
    }
    
    
    return 0;
}