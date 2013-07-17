#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

/*
	整个的想法是，从某一个数开始试，看看能不能加到这个数。
	这个数test_num，从小到大试，并且要求能够被所有数之和整除
	测试这个test_num能不能加到，纠结了挺久。
	最后用dfs做，在数组中大到小进行试验，如果加到了这个数，那么继续加，如果这条路走不通，
	那么往回退，直到可以加到为止。如果所有路都不能加到，那么该test_num不正确，试下一个test_num


*/

//得到当前数组的最大值
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

//得到下一个可以用的数
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
	int b[1000];//用来记录dfs走过的路径
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
			
			//看看是不是加到了一次test_num
			if((i+current_sum)%test_num == 0){
				b[count]=i;
				count++;
				stick[i]--;
				find = true;
				current_sum += i;
				max_second = get_current_max(stick, max);
				break;				
			}
			//如果能加，先加大的
			else{
				//如果这是新开始的一个test_num，而且不是当前数组中最大的数，不用加了，此路不通
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

		//用于回退
		//如果没找到，那么需要把用于记录路径的b数组中某些内容清除，count减少，再把数组中内容加上
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
					//如果一直找到最开始的最大值都没找到，那么返回没找到，返回之前，要把改过的值加进去
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
		//给测试值时，要能让总数整除，这样可以减少总次数
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