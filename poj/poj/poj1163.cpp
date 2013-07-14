#include <iostream>

using namespace std;

int line;
int triangle[100][100];
int dp_max[100][100];
int total_max;


//dp
//ÀÆÃ‚

int main(){

	scanf("%d", &line);

	// ‰»Î
	for(int i=0; i<line; i++){
		for(int j=0; j<i+1;j++){
			scanf("%d", &triangle[i][j]);
		}
	}

	dp_max[0][0] = triangle[0][0];

	for(int i=1; i<line; i++){
		dp_max[i][0] = dp_max[i-1][0]+triangle[i][0];
		dp_max[i][i] = dp_max[i-1][i-1]+ triangle[i][i];
		for(int j=1; j<i; j++){
			dp_max[i][j] = (dp_max[i-1][j-1]>dp_max[i-1][j])?dp_max[i-1][j-1]:dp_max[i-1][j];	
			dp_max[i][j] += triangle[i][j];
		}
	}

	int total_max=0;
	for(int j=0; j<line; j++){
		total_max = (total_max > dp_max[line-1][j])?total_max:dp_max[line-1][j];
	}

	printf("%d\n",total_max);


	return 0;

}