#include <iostream>

using namespace std;
const int MAX_INPUT = 100000;

int calculate(float bound){
	int n=1;
	double sum=0;
	while(sum < bound){
		n++;
		sum += (double)1/n; 
	}
	
	return n-1;
}

int main(){


	float a = 0;
	cin>>a;

	int count = 0;
	int out[MAX_INPUT];
	while(a != 0.00)
	{
		out[count] = calculate(a);
		cin>>a;
		count++;
	}
	for(int i=0; i<count; i++){
		cout<<out[i]<<" "<<"card(s)"<<endl;
	}


	return 0;
}