#include <iostream>

int main(){

	int line;
	scanf("%d", &line);

	int m, n;
	for(int i=0; i<line; i++){
		scanf("%d%d", &m, &n);
		if(m >= n){
			printf ("MMM BRAINS\n");
		}
		else{
			printf ("NO BRAINS\n");
		}
	
	}


	return 0;
}