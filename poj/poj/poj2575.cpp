#include <iostream>


int a[3000*2];

int absolute(int num){
	if(num < 0){
		num = -num;
	}
	return num;
}

void skip(int i, int line){
	int temp;
	for(;i<line-1; i++){
		scanf("%d", &temp);
	}
}

int main(){

	int line,n,last;
	while(scanf("%d", &line) != EOF){
		if(line == 1){
			printf("Jolly\n");
			scanf("%d", &last);
			continue;
		}
		memset(a, 0, sizeof(int)*3001*2);
		scanf("%d", &last);
		int i;
		for(i=1; i<line; i++){
			scanf("%d", &n);
			int temp_diff = absolute(n-last); 
			if(temp_diff > line-1 || temp_diff == 0 || a[temp_diff] != 0){
				skip(i, line);
				printf("Not jolly\n");
				break;
			}
			else {
				a[temp_diff] = 1;
			}
			last = n;
		}
		
		if(i == line){
			printf("Jolly\n");
		}		

	}

	return 0;
}