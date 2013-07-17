#include <iostream>

using namespace std;


int get_max(int a[100][100], int color[100][100], int r, int c, int &temp_i, int &temp_j){
	int max = -1;
	temp_i = -1;
	temp_j = -1;
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if(a[i][j]>=max && color[i][j] == 0){
				max = a[i][j];
				temp_i = i;
				temp_j = j;
			}
		}
	}	
	if(temp_i >= 0 && temp_j >= 0){color[temp_i][temp_j]=1;}
	return max;
}


int get_near();

int count=0;

int dfs(int a[100][100], int color[100][100], int r, int c, int current, int row, int column, int level){
	
	if(row!=0){
		if(a[row-1][column]<current && a[row-1][column] > count-level){
			color[row-1][column] = 1;
			dfs(a,color,r,c, a[row-1][column], row-1, column, level+1);
		}	
	}

	if(row != r-1){
		if(a[row+1][column]<current && a[row+1][column] > count-level){
			color[row+1][column] = 1;
			dfs(a,color,r,c, a[row+1][column], row+1, column, level+1);
		}
	}

	if(column != 0){
		if(a[row][column-1]<current && a[row][column-1] > count-level){
			color[row][column-1] = 1;
			dfs(a,color,r,c, a[row][column-1], row, column-1, level+1);
		}	
		
	}

	if(column != c-1){
		if(a[row][column+1]<current && a[row][column+1] > count-level){
			color[row][column+1] = 1;
			dfs(a,color,r,c, a[row][column+1], row, column+1, level+1);
		}	

	}

	count = (count>level)?count:level;

	return 0;
}

int main(){
	int a[100][100];
	int color[100][100];
	int r,c;
	int temp;
	cin>>r>>c;
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			cin>>temp;
			a[i][j] = temp;
			color[i][j]=0;
		}
	}

	int temp_i=0,temp_j=0;
	int max = get_max(a,color,r,c,temp_i, temp_j);
	

	do{		
		dfs(a,color,r,c, max, temp_i, temp_j, 1);
		max = get_max(a,color,r,c,temp_i, temp_j);

	}while(max!=-1);



	cout<<count<<endl;




	return 0;

}