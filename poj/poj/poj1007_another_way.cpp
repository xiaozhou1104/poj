#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){

	int length,size;
	cin>>length>>size;
	int revert[1000];
	int temp_revert[1000];
	string input[1000];
	for(int i=0; i<size; i++){
		cin>>input[i];
		int count=0;
		for(int j=0; j<length; j++){
			for(int k=j; k<length; k++){
				if(input[i].at(j) > input[i].at(k)){
					count++;
				}
			}
		}
		revert[i] = count;
		temp_revert[i] = count;
	}

	sort(temp_revert, &temp_revert[size]);
	int i=0;
	while(i != size){
		for(int j=0; j<size; j++){
			if(revert[j] == temp_revert[i]){
				cout<<input[j]<<endl;
				i++;
				if(temp_revert[i] != temp_revert[i-1]){
					break;
				}
			}
		}
	}
	


	return 0;
}