#include <iostream>
#include <string>

using namespace std;

//string加法
string str_add(string str1, string str2){

	//确定哪个string更长
	string *max, *min;
	if(str1.length() < str2.length()){	
		max = &str2;
		min = &str1;
	}
	else {
		max = &str1;
		min = &str2;
	}
	int d_value = max->length() - min->length();
	string new_str(*max);

	// 算出两个string的加
	int max_length = max->length();
	int add_bit = 0;
	int max_value;
	int min_value;
	int min_exist;
	int add_num = 0;
	for(int i=max_length-1; i>=0; i--){
		//判断最小长度的是否已经加完
		min_exist = i >= d_value ? 1:0;
		
		max_value = (*max).at(i)-'0';
		if(min_exist == 1){min_value = (*min).at(i-d_value)-'0';}

		add_num = max_value + min_value*min_exist + add_bit;

		new_str.at(i) = (char)(add_num%10) + '0';
		add_bit = add_num/10;
	}
	//确定是否在最前面要加一位;
	if(add_bit == 1){
		new_str.insert(0,"1");
	}	

	return new_str;
}

string str_multi_char(string new_str, char multi){
	int mul = multi - '0';
	int mul_num;
	int add_bit = 0;
	//逐位乘
	for(int i=new_str.length()-1; i>=0; i--){
		mul_num = (new_str.at(i)-'0')*mul + add_bit;		
		add_bit = mul_num/10;
		new_str.at(i) = (char)(mul_num % 10) + '0';
	}
	//确定最前面是否有进位
	if(add_bit > 0){
		new_str.insert((unsigned int)0, (unsigned int)1,(char)add_bit+'0');
	}

	return new_str;
}



string str_multi(string new_str, string old_str){
	string multi_str("0");

	for(int i=(int)old_str.length()-1; i>=0; i--){
		//new_str对底数逐位乘
		string temp = str_multi_char(new_str, old_str.at(i));
		//对偏移的位，乘以相应个10
		temp.append(old_str.length()-1-i,'0');
		//把新值加到multi_str中
		multi_str = str_add(multi_str, temp);
	}

	return multi_str;
}


int main(){

	string input;
	int n;
	
	int offset, total_offset;
	while(cin>>input>>n){
		
		//找到小数点，替换之，必须有小数点
		//替换后为整数+偏移量
		offset = input.find('.');
		input.erase(offset,1);
		offset = input.length() - offset;
		
		//总偏移量
		total_offset = offset*n;

		//做n次方运算
		string new_str(input);
		for(int j=0; j<n-1; j++){
			new_str = str_multi(new_str, input);
		}

		//小数点应该在的位置
		int offset_loc = new_str.length()-total_offset;
		new_str.insert((unsigned int)offset_loc, 1, '.');

		//去掉结尾的0
		for(int count=0,j=new_str.length()-1; j>=offset_loc; j--){
			if(new_str.at(j) == '0'){
				count+=1;
			}
			else{
				if(count!=0){
					//如果最后是0，直接删掉，如果是整数，把小数点也删掉
					if(new_str.at(j) != '.'){new_str.erase(j+1, count);}
					else {new_str.erase(j, count+1);}
				}
				break;
			}
		}

		//去掉开头的0
		for(int count=0,j=0; j<=offset_loc; j++){
			if(new_str.at(j) == '0'){
				count++;
			}
			else{
				if(count!=0){
					new_str.erase(0, count);
				}
				break;
			}
		}
		
		cout<<new_str<<endl;
	}


	return 0;

}
