#include <iostream>

const int MAXSIZE=100;
const int ERRNUM = -1;
int stock[MAXSIZE*2][MAXSIZE*2];

int n=0;

void floyd(){

	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(stock[i][k] != -1 && stock[k][j] != -1 ){
					if(stock[i][k] + stock[k][j] < stock[i][j] || stock[i][j] == -1){
						stock[i][j] = stock[i][k] + stock[k][j];
					}		
				}
			}		
		}	
	}
	
}


void print_ans(){
	int last_maxline_num = 0;
	int min_line = 0;
	int maxline_num = 0;
	bool finished = true;
	for(int i=1; i<=n; i++){
		maxline_num = stock[i][1];
		finished = true;
		for(int j=1; j<=n; j++){
			if(j == i){continue;}
			if(stock[i][j] == -1){
				finished = false;
				break;
			}
			else{
				if(stock[i][j] > maxline_num){
					maxline_num = stock[i][j];
				}
			}		
		}	
		if(finished){
			if(maxline_num < last_maxline_num || last_maxline_num == 0){
				min_line = i;
				last_maxline_num = maxline_num;
			}
		}
	}

	if(min_line == 0){
		printf("disjoint\n");
	}
	else{
		printf("%d %d\n", min_line, last_maxline_num);
	}

}


int main(){
	scanf("%d", &n);
	while(n!=0){

		for(int i=1; i<=MAXSIZE; i++){
			for(int j=1; j<MAXSIZE; j++){
				if(i == j){
					stock[i][j] = 0;
				}
				else{
					stock[i][j] = ERRNUM;
				}
			}	
		}
		int talk_num;
		for(int i=1; i<=n; i++){
			
			scanf("%d", &talk_num);
			for(int j=1; j<=talk_num; j++){
				int temp_j, temp_num;
				scanf("%d", &temp_j);
				scanf("%d", &stock[i][temp_j]);		
			}
		}

		floyd();

		print_ans();
	/*	for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				printf("%d %d %d\n", i, j, stock[i][j]);
			}
		}*/

		
		scanf("%d", &n);

	}
	return 0;
}