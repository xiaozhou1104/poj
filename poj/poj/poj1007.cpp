#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){

	multimap <int, string> data;
	int length,size;
	cin>>length>>size;

	for(int i=0; i<size; i++){
		string input;
		cin>>input;
		int count=0;
		for(int j=0; j<length; j++){
			for(int k=j; k<length; k++){
				if(input.at(j) > input.at(k)){
					count++;
				}
			}
		}
		data.insert(pair<int,string>(count,input));
	}

	multimap<int, string>::iterator it;
	for(it = data.begin(); it!=data.end(); it++){
		cout<<(*it).second<<endl;
	}



	return 0;

}