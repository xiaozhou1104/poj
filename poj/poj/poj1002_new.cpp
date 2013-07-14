#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

//网上做法
//学习之
//M 572K
//T 297MS


char s[31];

//哈希表，将0-9， A-Y（除去Q)处理方式值得学习
int Hash(){
	int sum = 0;
	for(int i=0, k=0; k<7; i++){

	if (s[i] >= '0' && s[i] <= '9'){
		sum *= 10;
		sum += s[i] - '0';
		k++;
	}
	else if(s[i] >= 'A' && s[i] < 'Z'){
		sum *= 10;
		sum += (s[i] - 'A' - (s[i]>'Q'))/3 + 2;
		k++;
	}
	}


	return sum;
}



int main(){

	int n; scanf("%d", &n);
	//开辟数组的方式可能不是很好，最坏情况下要100000的空间，sort操作时间较长
	int *data = new int[n]; getchar();

	for(int i=0; i<n; i++){
		gets(s);
		data[i] = Hash();
	}
	sort(data, data+n);
	bool nodulp = false;	
	for(int i=0; i<n-1; i++){
		int sum = 1;
		while(data[i] == data[i+1]){sum++; i++;}
		if(sum > 1)
		{
			//printf处理方式值得学习
			printf("%03d-%04d %d\n", data[i]/10000, data[i]%10000, sum);
			nodulp = true;
		}
	}

	if(!nodulp)
	{cout<<"No duplicates."<<endl;}

	delete data;

	return 0;
}
