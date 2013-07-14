#include <iostream>

using namespace std;

bool win_strg(int month, int day){
	bool result;
	//ÆæÊýÔÂ·Ý
	if((month + day)%2 == 0){result = true;}
	else
	{result = false;}

	if(month == 11 && day == 30){result = true;}
	if(month == 9 && day == 30){result = true;}

	return result;
}


int main(){

	int input_num;
	cin>>input_num;

	int year, month, day;
	for(int i=0; i<input_num; i++){
		cin>>year>>month>>day;
		if(win_strg(month, day)){cout<<"YES"<<endl;}
		else{cout<<"NO"<<endl;}	
	}

	return 0;
}