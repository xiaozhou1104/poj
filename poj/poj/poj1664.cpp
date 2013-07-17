#include <iostream>

using namespace std;


int count=0;

int dfs_search(int m, int n){

	if(m<0){return -1;}
	if(n==1){
		count++;
		return 0;
	}

	for(int k=0; k<=m/n; k++){
		if(dfs_search(m-n*k, n-1) == -1){
			return -1;
		}
	}

	return 0;
}





int main(){

	int test_num;

	cin>>test_num;

	for(int i=0; i<test_num; i++){
		int m, n;
		cin>>m>>n;
		count = 0;

		dfs_search(m, n);


		cout<<count<<endl;
	}




	return 0;

}