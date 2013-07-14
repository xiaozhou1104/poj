#include <iostream>

using namespace std;

int main(){

	float input = 0;
	float output = 0;

	for(int i=0; i<12; i++){
		cin>>input;
		output += input;
	}
	output = output/12;
	printf("$%.2f", output);

	return 0;
}