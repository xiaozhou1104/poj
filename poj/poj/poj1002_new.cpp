#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

//��������
//ѧϰ֮
//M 572K
//T 297MS


char s[31];

//��ϣ����0-9�� A-Y����ȥQ)����ʽֵ��ѧϰ
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
	//��������ķ�ʽ���ܲ��Ǻܺã�������Ҫ100000�Ŀռ䣬sort����ʱ��ϳ�
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
			//printf����ʽֵ��ѧϰ
			printf("%03d-%04d %d\n", data[i]/10000, data[i]%10000, sum);
			nodulp = true;
		}
	}

	if(!nodulp)
	{cout<<"No duplicates."<<endl;}

	delete data;

	return 0;
}
