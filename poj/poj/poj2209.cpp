#include <iostream>


int multi(int n, int exp){
	int sum=n;
	
	while(exp-->1){
		sum *= n;
	}

	return sum;
}

int main(){

	int son_num, exp_num;

	scanf("%d%d", &son_num, &exp_num);

	int sum = 0;
	int num;
	if(exp_num % 2 == 0){
		for(int i=0; i<son_num; i++){
			scanf("%d", &num);
			sum += multi(num, exp_num);	
		}
	
	}
	else{
		for(int i=0; i<son_num; i++){
			scanf("%d", &num);
			if(num > 0){
				sum += multi(num, exp_num);
			}
	
		}
	}
	printf("%d", sum);


	return 0;
}