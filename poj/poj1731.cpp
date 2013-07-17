#include <iostream>
#include <string>
using namespace std;

int al[26];
int tot_length;
char out_char[200];
string s_in;
int deep=0;

/*
string str_char_swap(int pos, string str){
	char temp;
	str.at(pos)
	
}
*/


void sort_str(string str, int level){
	if(level >= s_in.length()){
		return;
	}

	if(str.length() <= 1){
		cout<<str;
		return;
	}


	//最后一层，只有两个字符，直接输出
	if(str.length() == 2){
		for(int i=0; i<s_in.length()-2; i++){
					cout<<out_char[i];
				}
				cout<<str<<endl;
				if(str.at(0) != str.at(1)){
					for(int i=0; i<s_in.length()-2; i++){
						cout<<out_char[i];
					}
					cout<<str.at(1)<<str.at(0)<<endl;
				}
		return;
	}
	
	for(int start_str=0; start_str < str.length(); start_str++){

			if(start_str > 0 && str.at(start_str) == str.at(start_str-1)){
					continue;
			}

			string temp = str;
			if(level == 0){
				memset(out_char, 0, sizeof(char));
			}
				
				

				out_char[level] = str.at(start_str);
				
				sort_str(temp.erase(start_str, 1), level+1);
			
			
	}

}


int main(){

	
	cin>>s_in;
	memset(al, 0, 26*sizeof(int));


	//重置输入数组，使其按照字母表排序
	for(int i=0; i<s_in.length(); i++){
		al[s_in.at(i) - 'a'] += 1;
	}
	for(int i=0, j=0; i<26; i++){
		while(al[i] != 0){
			s_in.at(j) = i +'a';
			al[i]--;
			j++;
		}
	}
	tot_length = s_in.length();

	memset(out_char, 0, sizeof(char));
	sort_str(s_in, 0);



	return 0;
}