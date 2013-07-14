#include<iostream>

using namespace std;

int row[8];
int line[8];

int count;

int dfs(int chess[8][8], int n, int k, int level, int min_i){
	
	if(level==1){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(chess[i][j] == 1){
					row[0] = i;
					line[0] = j;
					dfs(chess, n, k-1, level+1, i+1);
				}
			}		
		}
	}
	else{
		if(k == 0){count++;return 0;}
		for(int i=min_i; i<n; i++){
			bool find_i = false;
			for(int k=0; k<level-1; k++){
				if(row[k] == i){find_i=true; break;}
			}
			if(find_i){continue;}

			for(int j=0; j<n; j++){
				bool find_j = false;
				for(int k=0; k<level-1; k++){
					if(line[k] == j){find_j=true; break;}
				}
				if(find_j){continue;}

				if(chess[i][j] == 1){
					row[level-1] = i;
					line[level-1] = j;
					dfs(chess, n, k-1, level+1, i+1);
				}
			}

		}
	}


	return 0;
}




int main(){


	int n,k;
	cin>>n>>k;
	int chess[8][8];
	while(n!=-1 && k!= -1){
		char a;
		for(int i=0; i<n;i++){
			for(int j=0; j<n;j++){
				cin>>a;
				chess[i][j] = (a-'.')/('#'-'.');
			}		
		}
		for(int i=0; i<8; i++){
			row[i] = -1;
			line[i] = -1;
		}
		count = 0;

		dfs(chess, n, k, 1, 0);
		cout<<count<<endl;

		cin>>n>>k;
	}
	return 0;
}