#include <iostream>

using namespace std;


int main(){


	int test_num;
	cin>>test_num;
	int s_seq[1000];
	int level[1000];
	int w_seq[1000];

	int data_num;
	for(int i=0; i<test_num; i++){
		
		cin>>data_num;
		for(int j=0; j<data_num; j++){
			cin>>s_seq[j];
		}
		level[0] = s_seq[0]-1;
		for(int j=0; j<data_num-1; j++){
			if(s_seq[j+1] == s_seq[j]){
				level[j+1] = level[j] - 1; 
			}
			else{
				level[j+1] = level[j] +(s_seq[j+1] - s_seq[j] -1);
		
			}
		}
		for(int j=0; j<data_num; j++){

			int count=1;
			for(int k=j-1; k>=0; k--){
				if(level[k] == level[j] + 1){
					count+=w_seq[k];
				}
				if(level[k] <= level[j]){
					break;
				}
			}
			w_seq[j] = count;
		}
		for(int j=0; j<data_num; j++){
			cout<<w_seq[j]<<" ";
		}
		cout<<endl;

	}



	return 0;
}
