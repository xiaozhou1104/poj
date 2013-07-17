#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;


int change(char);
bool isnum(char);

int main(){

	int a=0;
	string b;
	//cout<<"please enter the number "<<endl;
	cin>>a;	
	map<string, int> telephone;
	int m=0;
	while(m<a)
	{
		string tel;
		//读入一行string到b里
		cin>>b;
		m++;
		int k = 0;
		/*
		对一行string进行判断，如果出现'-'不管，出现字母进行替换，出现数字照抄
		*/
		for(int i=0; i<(int)(b.length()); i++)
		{
			if(b.at(i) == '-')
			{continue;}
			else 
			{
				if(k == 3)
				{tel.push_back('-'); k++;}
				if(isnum(b.at(i)) == false)
				{	//加'0'是为了让int转化为char型
					tel.push_back(change(b.at(i)) + '0');
				}
				else
				{tel.push_back(b.at(i));}
				k++;
			}
		}
		telephone[tel] += 1;
	}


	//迭代输出，如果出现次数为1，则不输出。
	map<string, int>::iterator it = telephone.begin();
	int noduplicates = 0;
	while(it != telephone.end())
	{
		
		if((*it).second != 1)
		{
			noduplicates += 1;
			cout<<(*it).first<<' '<<(*it).second<<endl;
		}
		it++;
	}
	if(noduplicates == 0)
	{cout<< "No duplicates."<<endl;}//之前忘了加这句话，交了6遍都是错。。。。


	return 0;
}

int change(char name)
{
	int changeto = 0;
	switch (name){
	case'A':
	case'B':
	case'C':
		changeto = 2;
		break;
	case'D':
	case'E':
	case'F':
		changeto = 3;
		break;
	case'G':
	case'H':
	case'I':
		changeto = 4;
		break;
	case'J':
	case'K':
	case'L':
		changeto = 5;
		break;
	case'M':
	case'N':
	case'O':
		changeto = 6;
		break;
	case'P':
	case'R':
	case'S':
		changeto = 7;
		break;
	case'T':
	case'U':
	case'V':
		changeto = 8;
		break;
	case'W':
	case'X':
	case'Y':
		changeto = 9;
		break;
	default:
		return -1;
	}
	return changeto;
}

bool isnum(char a){
	if (a<'0' ||a > '9')
		return false;
	else 
		return true;
}
