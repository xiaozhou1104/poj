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
		//����һ��string��b��
		cin>>b;
		m++;
		int k = 0;
		/*
		��һ��string�����жϣ��������'-'���ܣ�������ĸ�����滻�����������ճ�
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
				{	//��'0'��Ϊ����intת��Ϊchar��
					tel.push_back(change(b.at(i)) + '0');
				}
				else
				{tel.push_back(b.at(i));}
				k++;
			}
		}
		telephone[tel] += 1;
	}


	//���������������ִ���Ϊ1���������
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
	{cout<< "No duplicates."<<endl;}//֮ǰ���˼���仰������6�鶼�Ǵ�������


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
