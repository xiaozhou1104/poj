#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main(){
	
	int n;
	int input[100];
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		scanf("%d", &input[i]);
	}
	std::vector<int> myvector (input, input+n);
	std::sort(myvector.begin(), myvector.end());

	double sum;
	if(n > 1){
		sum = 2 * sqrt((double)myvector.at(n-1) * (double)myvector.at(n-2));

		for(int i=n-3; i>=0; i--){
			sum = 2 * sqrt(sum * (double)myvector.at(i));	
		}
	}
	else{
		sum = myvector.at(0);
	}

	printf("%.3f", sum);


	return 0;
}