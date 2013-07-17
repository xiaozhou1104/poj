#include <iostream>

using namespace std;

unsigned int init_state[16];
unsigned int final_state[16];
//��ÿ����Ҫת��������Ϊ7����������ظ�������Ҫ����
void add_relate(int loc){
	int temp = loc;
	//һ�е�����
	while(temp-4 >= 0){
		temp = temp-4;
		final_state[temp] += 1;
	}
	//һ�е�����
	temp = loc;
	while(temp+4 < 16){
		temp = temp+4;
		final_state[temp] += 1;
	}
	//һ�е�4����1
	temp = loc;
	for(int i=0; i<4; i++){
		final_state[temp-temp%4+i] += 1;	
	}

}

//������Ҫ���Ĵ�����������Ҫ���Ĵ�������final_state������
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
	//�������ݣ���'-'��Ϊ1,��'+'��Ϊ0,����init_state������
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