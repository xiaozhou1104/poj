
#include <iostream>

using namespace std;

int a[1000][1000];
int array_sum[1000][1000];

const int INF = 127;
int total_max = -INF;

//类似于dp的做法，存储每个矩阵相对于第一行第一列元素的和
void set_sum(int line){
	array_sum[0][0] = a[0][0];
	for(int i=1; i<line; i++){
		array_sum[i][0] = array_sum[i-1][0] + a[i][0];	
	}
	for(int j=1; j<line; j++){
		array_sum[0][j] = array_sum[0][j-1] + a[0][j];
	}

	for(int i=1; i<line; i++){
		for(int j=1; j<line; j++){
				array_sum[i][j] = a[i][j] + array_sum[i-1][j] + array_sum[i][j-1] - array_sum[i-1][j-1];
		}
	}
	
}

//对于对于每两个顶点，确定以其为顶点的矩形的和
void get_max(int cur_i, int cur_j, int target_i, int target_j){

	int result;
	int d = array_sum[target_i][target_j];
	int b=0;
	int	c=0;
	int a=0;
	if(cur_i == 0 && cur_j == 0){
		b=0;
		c=0;
		a=0;
	}
	else
	{
		if(cur_j == 0){
			c = array_sum[cur_i-1][target_j]; 
			a = 0;
		}
		else if(cur_i == 0){
			b = array_sum[target_i][cur_j-1];
			a = 0;
		}
		else{
			b = array_sum[target_i][cur_j-1];
			c = array_sum[cur_i-1][target_j]; 
			a = array_sum[cur_i-1][cur_j-1];
		}
		
	}
	result = d+a-b-c;

	if(result > total_max){
		total_max = result;
	}

}

int main(){


	int line=0;
	scanf("%d",&line);

	for(int i=0; i<line; i++){
		for(int j=0; j<line; j++){	
			scanf("%d",&a[i][j]);
			//maxi[i][j] = a[i][j];
		}
	}

	set_sum(line);

	//遍历所有矩形，对任意两个顶点，算出其和
	for(int i=0; i<line; i++){
		for(int j=0; j<line; j++){
		
			for(int temp_i=i; temp_i<line; temp_i++){
				for(int temp_j=j; temp_j<line; temp_j++){
						get_max(i, j, temp_i, temp_j);				
				}			
			}
		}
	}




	printf("%d\n",total_max);



	return 0;
}
