//
//  poj1547.cpp
//  poj
//
//  Created by zhou on 13-6-15.
//  Copyright (c) 2013年 zhou. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(){
    
    int n;
    cin>>n;
    
    int student[9];
    string stu_name[9];
    
        while (n!= -1) {
            int sum = 0;
            int bully=-1, victim=-1;

            int temp_a, temp_b, temp_c;
            string temp_name;
            int v;
        for (int i=0; i<n; i++) {
            cin>>temp_a>>temp_b>>temp_c>>stu_name[i];
            v = temp_a * temp_b * temp_c;
            student[i] = v;
            sum += v;
        }
            
            
            for(int i=0; i< n; i++){
                if(student[i] == sum/n){
                    continue;
                }
                else if(student[i] < sum/n){
                    victim = i;
                }
                else{
                    bully = i;
                }
            }
            cout<<stu_name[bully]<<" took clay from "<<stu_name[victim]<<"."<<endl;
            
             cin>>n;
    }
    
    
    
    return 0;
}
