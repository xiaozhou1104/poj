#include <iostream>
#include <math.h>

using namespace std;

int calculate_is_N(int L[], int H[], int M, int N);

int min_num = 10000;

int first_max = 0;
int current_multi = 0;

int H_level_max[20];

int maximal(int i, int j){
	return (i>j)?i:j;
}


int minimal(int i, int j){
	return (i<j)?i:j;
}


int get_current_max(int L[], int H[], int M, int N, int level, int L_H){
	
	double count = 0;
	int sum = N;
	int temp_sum=0;
	switch(L_H){
	case 1:		
		for(int i=0; i<level-1; i++){
				sum -= L[i]*L[i]*H[i];
		}		
		count = sqrt((double)(sum/(level*(M-level+1))));
		break;
	case 0:
		for(int i=0; i<level-1; i++){
				sum -= L[i]*L[i]*H[i];
		}		
		for(int i=level-1; i<M; i++){
			temp_sum += L[i]*L[i];
		}
		count = sum/temp_sum;
		break;
	}

	return (int)count;

}

//跟问题中计数相反，M层为数组下标0
int calculate_S(int L[], int H[], int M){
	int sum=0;
	for(int i=0; i<M; i++){
		sum += 2*L[i]*H[i];
	}
	sum += L[M-1]*L[M-1];
	return sum;
	
}

//判断是不是到N了，如果是，返回0，计算值；如果大于，返回-1，那么此路径不再走了；
//如果小于，返回1，路径继续走
int calculate_is_N(int L[], int H[], int M, int N){
	int sum = 0;
	for(int i=0; i<M; i++){
		sum += L[i]*L[i]*H[i];
	}
	if(sum == N){return 0;}
	else if(sum > N){return -1;}
	else{
		return 1;
	}

}


bool calculate_is_over(int L[], int H[], int M, int N, int level, int L_H){
	switch(L_H){
	case 1:
		for(int i=level; i<M; i++){
			L[i] = L[i-1]+1;
		}
		break;
	case 0:
		for(int i=level; i<M; i++){
			H[i] = H[i-1]+1;
		}
		break;
	}
	int sum = calculate_S(L,H,M);
	if(sum > min_num){return true;}
	else{
		return false;
	}

}


int dfs_H(int H[], int L[], int M, int level_H, int N, int start){
	if(level_H == 1 && M != 1){
		int temp_max=first_max+level_H-1;
		temp_max = minimal(temp_max, H_level_max[level_H-1]);
		for(int i=1; i<=temp_max; i++){
			H[level_H-1] = i;
			int temp=0;
			//算一下当前是否已经超出
			if(min_num != 10000){
				if(calculate_is_over(L,H,M,N,level_H,0)){temp = -1;}
			}
			if(temp !=-1){
				temp = dfs_H(H, L, M, level_H+1, N, i);
			}
			if(temp == -1){
				if(i==1){	
					return -1;
				}
				else{return 0;}
			}
		}
	}
	else if(level_H == M){
		
		int temp_N = N;
		for(int i=0; i<M-1; i++){
			temp_N -= L[i]*L[i]*H[i];
		}
		if(temp_N < L[M-1]*L[M-1]*(H[M-2]+1)){
			return -1;
		}
		if(temp_N%(L[M-1]*L[M-1]) == 0){
			H[level_H-1] = temp_N/(L[M-1]*L[M-1]);
			int temp_min = calculate_S(L, H, M);
			min_num = (temp_min < min_num) ? temp_min : min_num;
			current_multi = 0;
			for(int k=0; k<M; k++){
				current_multi += L[k]*L[k];
			}	
		}
		return 0;
	}
	else{
		int temp_max = get_current_max(L, H, M, N, level_H, 0);
		temp_max = minimal(temp_max, first_max+level_H-1);
		temp_max = minimal(temp_max, H_level_max[level_H-1]);
		for(int j= start+1; j<=temp_max; j++){
			H[level_H-1] = j;
			int temp=0;
			//算一下当前是否已经超出		
			if(min_num != 10000){
				if(calculate_is_over(L,H,M,N,level_H,0)){temp = -1;}
			}
			if(temp !=-1){
				temp = dfs_H(H, L, M, level_H+1, N, j);
			}

			if(temp == -1){
				if(j == start + 1){									
					H_level_max[level_H-1] = j-1; 
					return -1;
				}
				else{
					return 0;
				}
			}
		}

	}
}


int dfs_L(int H[], int L[], int M, int level, int N, int start){
	if(level == 1 && M != 1){
		for(int i=1; i<=first_max+level-1; i++){
			L[level-1] = i;			
			dfs_L(H, L, M, level+1, N, i);
		}
	}
	else if(level == M){
		for(int k= start+1; k<=first_max+level-1; k++){
			L[level-1] = k;
			//算一下当前是否已经超出
			int sum = calculate_is_N(L, H, level, N);
			int j;
			int temp_multi=0;
			switch(sum){
				int temp_min;
				case 1:
					
					//for(j=0; j<M; j++){
					//	temp_multi += L[j]*L[j];
					//}	
					//if(temp_multi >= current_multi){
						dfs_H(H, L, M, 1, N, 0);
					break;
				case 0:
					temp_min = calculate_S(L, H, M);
					min_num = (temp_min < min_num) ? temp_min : min_num;
					if(k == start+1){return -1;}
					else{
						return 0;
					}
				case -1:
					if(k == start+1){return -1;}
					else{
						return 0;
					}
			}			
			for(int i=0; i<M; i++){
				H[i] = i+1;
			}
		}
	}

	else{
		int temp_max = get_current_max(L, H, M, N, level, 1);
		temp_max = minimal(temp_max, first_max+level-1);
		for(int j= start+1; j<=temp_max; j++){
			L[level-1] = j;
			//算一下当前是否已经超出
				int temp=0;
				if(min_num != 10000){
				if(calculate_is_over(L,H,M,N,level,1)){temp = -1;}
			}
				if(temp !=-1){
					temp = dfs_L(H, L, M, level+1, N, j);	
				}					
				if(temp == -1){
					if(j == start+1){return -1;}
					else {return 0;}
				}
		}

	}

}

int main(){

	int N,M;
	cin>>N>>M;

	int L[20], H[20];
	int min_S = 0;

	double temp_a;
	temp_a = sqrt((double)(2*N- pow((double)M,4)/2));
	first_max = (int)temp_a/M + 1;

	for(int i=0; i<M; i++){
		L[i] = i+1;
		H[i] = i+1;
		H_level_max[i] = first_max + i;
	}

	

	dfs_L(H, L, M, 1, N, 0);

	if(min_num == 10000){
		cout<<"0"<<endl;
	}
	else{
		cout<<min_num<<endl;
	}

	return 0;
}