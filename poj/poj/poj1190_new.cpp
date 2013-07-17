#include <iostream>
#include <math.h>


using namespace std;



//最后还是用了网上人的思路
//自己原来的用两个dfs做，先算半径，再算高度，剪枝很难剪
//在这个里面，有一个很巧妙的剪枝

int min_num = 100000;

int calculate_S(int R[], int H[], int M){
	int sum=0;
	for(int i=0; i<M; i++){
		sum += 2*R[i]*H[i];
	}
	sum += R[0]*R[0];
	return sum;	
}

int calculate_current_S(int R[], int H[], int level){
	int sum=0;
	for(int i=0; i<level-1; i++){
		sum += 2*R[i]*H[i];
	}
	if(level > 1){
		sum += R[0]*R[0];
	}
	return sum;	
}


int dfs(int H[], int R[], int M, int N, int level, int s, int r_last_num, int h_last_num){
	if(level == M){
		if(s<=0){return -1;}//如果剩下的体积不够，那么结束
		if(r_last_num<1 || h_last_num<1){return -1;}//如果最大能用的数不为整数，那么结束
		int current_S = calculate_current_S(R,H,level);
		for(int i=r_last_num; i>=M-level+1; i--){
			R[level-1] = i;
			//小的圆柱在同等体积时，会产生更大的侧面积
			if(2*s/R[level-1] + current_S > min_num){return -1;}
			for(int j=h_last_num; j>=M-level+1; j--){
				H[level-1] = j;
				if(R[level-1]*R[level-1]*H[level-1] == s){
					int temp_min = calculate_S(R,H,M);
					min_num = (temp_min < min_num) ? temp_min : min_num;
				}
				else if(R[level-1]*R[level-1]*H[level-1] < s){
					break;
				}
			}
		}
	}

	else{
		if(r_last_num<1 || h_last_num<1){return -1;}
		if(s<=0){return -1;}
		int current_S = calculate_current_S(R,H,level);
		for(int i=r_last_num; i>=M-level+1; i--){
			R[level-1] = i;
			if(2*s/R[level-1] + current_S > min_num){return -1;}
			for(int j=h_last_num; j>=M-level+1; j--){
				H[level-1] = j;
				dfs(H, R, M, N, level+1, s-R[level-1]*R[level-1]*H[level-1],i-1,j-1);
			}
		}

	}


}


int main(){

	int N,M;
	cin>>N>>M;

	int R[20], H[20];

	for(int i=0; i<M; i++){
		R[i] = i+1;
		H[i] = i+1;
	}

	int r_max = (int)sqrt((double)N/(double)M);
	int h_max = (int)pow((double)(6*N), 1.0/3);

	dfs(H, R, M, N, 1, N, r_max, h_max);

	if(min_num == 100000){
		cout<<"0"<<endl;
	}
	else{
		cout<<min_num<<endl;
	}





	return 0;
}