#include <iostream>
#include <queue>

const int MAX = 100000;

int loc[MAX*2];

int main(){

	for(int i=0; i<MAX*2; i++){
		loc[i] = MAX + 1;
	}
	int n, k;
	scanf("%d%d", &n, &k);


	if(n >= k){
		printf("%d\n", n-k);
	}
	else{
		std::queue <int> q1;
		q1.push(n);
		loc[n] = 0;

		while(!q1.empty()){
			int temp = q1.front();
			q1.pop();
			if(temp + 1 < k * 2 && loc[temp + 1] > MAX){
				loc[temp+1] = loc[temp] + 1;
				q1.push(temp+1);
			}
			if(temp - 1 > 0 && loc[temp - 1] > MAX ){
				loc[temp-1] = loc[temp] + 1;
				q1.push(temp-1);
			}
			if(temp * 2 < k * 2 && loc[temp * 2] > MAX){
				loc[temp*2] = loc[temp] + 1;
				q1.push(temp*2);
			}
			if(temp + 1 == k || temp - 1 == k || temp * 2 == k){
				printf("%d\n", loc[k]);
				break;
			}
		
		}

	}



	return 0;
}