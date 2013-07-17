#include<iostream>

using namespace std;


const float PI = 3.1415927;

int calculate_year(float dis_multi){

	int a = PI*dis_multi/100;

	return a+1;
	
}


int main(){

	int data_num;
	cin>>data_num;

	float input_x;
	float input_y;
	for(int i=0; i<data_num; i++){
		cin>>input_x>>input_y;
		printf("Property %d: This property will begin eroding in year %d.\n", 
				i+1, calculate_year(input_x*input_x + input_y*input_y));	
	}
	printf("END OF OUTPUT.\n");

	return 0;

}