#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

/*
	�������뷨�ǣ���ĳһ������ʼ�ԣ������ܲ��ܼӵ��������
	�����test_num����С�����ԣ�����Ҫ���ܹ���������֮������
	�������test_num�ܲ��ܼӵ���������ͦ�á�
	�����dfs�����������д�С�������飬����ӵ������������ô�����ӣ��������·�߲�ͨ��
	��ô�����ˣ�ֱ�����Լӵ�Ϊֹ���������·�����ܼӵ�����ô��test_num����ȷ������һ��test_num


*/

//�õ���ǰ��������ֵ
int get_current_max(int stick[], int old_max){
	for(int i=old_max; i>=1; i--){
		if(stick[i]!=0){
			return i;
		}
	}
	return 0;
}

int minimal(int a, int b){
	return (a<b)?a:b;
}

//�õ���һ�������õ���
int next_min(int stick[], int max_second){
	for(int i=max_second-1; i>=1; i--){
			if(stick[i]!=0){
				return i;
			}
	}
	return 0;
}



int calculate_num(int test_num, int max, int sum, int stick[51]){
	

	int max_num = stick[max];
	int count=0;
	int current_sum = max;
	bool find = false;
	int max_second = max;
	int b[1000];//������¼dfs�߹���·��
	for(int i=0; i<1000; i++){
		b[i] = 0;
	}	
	b[0] = max;
	stick[max]--;
	count++;
	while(sum != current_sum){
		
		find = false;
		int i;
		for(i=max_second; i>=1; i--){
			if(stick[i] == 0){
				continue;
			}
			if(current_sum%test_num + i > test_num){
				continue;
			}
			
			//�����ǲ��Ǽӵ���һ��test_num
			if((i+current_sum)%test_num == 0){
				b[count]=i;
				count++;
				stick[i]--;
				find = true;
				current_sum += i;
				max_second = get_current_max(stick, max);
				break;				
			}
			//����ܼӣ��ȼӴ��
			else{
				//��������¿�ʼ��һ��test_num�����Ҳ��ǵ�ǰ�����������������ü��ˣ���·��ͨ
				if(current_sum%test_num == 0 && max_second < get_current_max(stick, max)){
					break;
				}
				b[count] = i;
				count++;
				stick[i]--;
				current_sum += i;
				max_second = minimal((test_num - current_sum%test_num), max_second);
				find = true;
				i++;
			}			
		}

		//���ڻ���
		//���û�ҵ�����ô��Ҫ�����ڼ�¼·����b������ĳЩ���������count���٣��ٰ����������ݼ���
		if(find == false){
			if(count>2 && get_current_max(stick, max) == b[count-1] && b[count-1]>b[count-2]){			
					count--;
					stick[b[count]]++;
					current_sum -= b[count];
					b[count] = 0;	

					do{
						count--;
						stick[b[count]]++;
						current_sum -= b[count];
						max_second = next_min(stick, b[count]);
						b[count] = 0;
					}while(count>1 && max_second <1);
			}
			else{
				if(count > 1){
					do{
						count--;
						stick[b[count]]++;
						current_sum -= b[count];
						max_second = next_min(stick, b[count]);
						b[count] = 0;
					}while(count>1 && max_second < 1);
				}
				else{
					//���һֱ�ҵ��ʼ�����ֵ��û�ҵ�����ô����û�ҵ�������֮ǰ��Ҫ�ѸĹ���ֵ�ӽ�ȥ
					for(int k=999; k>=0; k--){
						if(b[k] != 0){
							stick[b[k]] += 1;
							b[k] = 0;
						}
					}
					return -1;
				}
			}


		}
			
		
	}	
		
	return test_num;
}


int main(){

	
	int input_num;
	int input;
	cin>>input_num;
	while(input_num != 0){
		int stick[51];
		for(int i=0; i<51; i++){
			stick[i] = 0;
		}
		int total = 0;
		int max = 0;
		int min = 0;
		for(int i=0; i<input_num; i++){
			cin>>input;
			total += input;
			if(input > max){max = input;}
			stick[input] += 1;
		}

		int length = -1;
		//������ֵʱ��Ҫ���������������������Լ����ܴ���
		for(int i=total/max; i>=1; i--){
			if(total%i != 0){continue;}
			length = calculate_num(total/i, max, total, stick);
			if(length != -1){break;}
		}

		if(length == -1){cout<<total<<endl;}
		else{cout<<length<<endl;}

		cin>>input_num;
	}

	return 0;

}