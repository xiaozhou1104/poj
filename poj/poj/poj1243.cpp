#include <iostream>

using namespace std;


const int XY=40;
int dp_array[XY][XY];

void dp(){

	for(int i=1; i<XY; i++){		
		for(int j=0; j<XY; j++){
			if(i==1){
				dp_array[1][j] = 1;
				continue;
			}		
			if(j>i){
				dp_array[i][j] = dp_array[i][i];
				continue;
			}
			if(j==0){
				dp_array[i][j] = i;
				continue;
			}
			dp_array[i][j] = dp_array[i-1][j-1] + dp_array[i-1][j] + 1;		
		}	
	}

}


int main(){

	int g=-1,l=-1;

	dp();

	scanf("%d%d",&g,&l);
	int count=1;
	while(g!=0 || l!=0){		
		printf("Case %d: %d\n", count++, dp_array[g][l]);
		scanf("%d%d",&g,&l);	
	}



	return 0;
}