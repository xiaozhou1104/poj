#include <iostream>

using namespace std;

unsigned int init_state[16];
unsigned int final_state[16];
//将每个需要转换的数分为7步，如果有重复，则不需要做。
void add_relate(int loc){
	int temp = loc;
	//一列的上面
	while(temp-4 >= 0){
		temp = temp-4;
		final_state[temp] += 1;
	}
	//一列的下面
	temp = loc;
	while(temp+4 < 16){
		temp = temp+4;
		final_state[temp] += 1;
	}
	//一行的4个加1
	temp = loc;
	for(int i=0; i<4; i++){
		final_state[temp-temp%4+i] += 1;	
	}

}

//返回需要做的次数，并将需要做的次数放在final_state数组中
int judge_switch(){
	for(int i=0; i<16; i++){
		if(init_state[i] == 0){
			add_relate(i);		
		}	
	}
	int count = 0;
	for(int i=0; i<16; i++){
		if(final_state[i] >1){
			final_state[i] = final_state[i]%2;
		}
		if(final_state[i] == 1){
			count += 1;
		}
	}
	return count;
}

int main()
{
	//读入数据，把'-'变为1,把'+'变为0,存在init_state数组中
	for(int i=0; i<4; i++){
		char temp[5];
		cin>>temp;
		for(int j=0; j<4; j++){
			init_state[4*i+j] = (temp[j] - '+')/('-' - '+');
			final_state[4*i+j] = 0;
		}
	}

	cout<<judge_switch()<<endl;
	for(int i=0; i<16; i++){
		if(final_state[i] == 1){
			cout<<i/4 + 1<<" "<<i%4 + 1<<endl;
		}
	}
	


	return 0;
}