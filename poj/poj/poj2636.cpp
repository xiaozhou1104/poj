#include <iostream>

int main(){

	int line;
	scanf("%d", &line);
	for(int i=0; i<line; i++){
		int n;
		int sum = 0;
		scanf("%d", &n);
		int single_strip;
		for(int j=0; j<n; j++){
			scanf("%d", &single_strip);
			sum += single_strip;
		}
		sum -= n-1;
		printf("%d\n", sum);	
	
	}


	return 0;
}