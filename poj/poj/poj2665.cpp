#include <iostream>

int main(){

	int line;
	int region_num;
	scanf("%d%d", &line, &region_num);
	while(!(line == 0 && region_num == 0)){
		int sum = line + 1;
		int start_loc, end_loc;
		for(int i=0; i<region_num; i++){
			scanf("%d%d", &start_loc, &end_loc);
			sum -= end_loc - start_loc + 1;
		}
		printf("%d\n", sum);
		scanf("%d%d", &line, &region_num);
	}



	return 0;
}