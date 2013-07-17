#include <stdio.h>
#include <math.h>

//这道题做的很dt，由于double和long double的精度都不够
//把分数的分子分母分别存在两个数组里,如果可以约分，进行约分
//dp部分比较简单

long long int p1[1500]={0};
long long int p2[1500]={0};
int input_nail[1500]={0};

int get_left(int i, int line){return i-line;}
int get_right(int i, int line){return i-line+1;}
int get_top(int i, int line){return i-2*line+2;}

long long int get_max(long long int i, long long int j, long long int k){
	int max = 0;
	if(i > j){
		if(i > k){
			max = i;
		}
		else {
			max = k;
		}
	}
	else{
		if(j > k){
			max = j;
		}
		else{
			max = k;
		}	
	}
	return max;
}

int main(){


	int n,m;
	scanf("%d%d",&n,&m);

	char temp;
	for(int i=1;i<=(n+1)*n/2;){
		scanf("%c", &temp);
		if(temp == '*'){
			input_nail[i] = 1;
			i++;
		}
		else if(temp == '.'){
			input_nail[i] = 0;
			i++;
		}
	}
	for(int i=(n+1)*n/2+1; i<=(n+2)*(n+1)/2; i++){
		input_nail[i] = 1;
	}

	
	p1[1] = 1;
	int line=2;
	for(int i=2; i<=(n+2)*(n+1)/2; i++){

		long long int temp_left=0, temp_right=0, temp_top=0, temp_left1=0, temp_right1=0, temp_top1=0;
		//如果是最右边一行的点
		if(i == line * (line+1) / 2){
			if(input_nail[get_left(i,line)] != 0){
				p1[i] = p1[get_left(i,line)];
				p2[i] = p2[get_left(i,line)]+1;
			}
			else{
				p1[i] = 0;
				p2[i] = 0;
			}
		}
		//如果是最左边一行的点
		else if(i == 1 + line * (line-1) / 2){
			if(input_nail[get_right(i,line)] != 0){
				p1[i] = p1[get_right(i,line)];
				p2[i] = p2[get_right(i,line)] + 1;
			}
			else{
				p1[i] = 0;
				p2[i] = 0;
			}
		}
		//如果是中间的点
		else {
			if(input_nail[get_left(i,line)] != 0){
				temp_left = p1[get_left(i,line)];
				temp_left1 = p2[get_left(i,line)] + 1;
			}
			if(input_nail[get_right(i,line)] != 0){
				temp_right = p1[get_right(i,line)];
				temp_right1 = p2[get_right(i,line)] + 1;
			}
			if(input_nail[get_top(i,line)] == 0){
				temp_top = p1[get_top(i,line)];
				temp_top1 = p2[get_top(i,line)];
			}
			long long int temp_max = get_max(temp_left1, temp_right1, temp_top1);
			temp_left = temp_left<<(temp_max - temp_left1);
			temp_right = temp_right<<(temp_max - temp_right1);
			temp_top = temp_top<<(temp_max - temp_top1);

			p1[i] = temp_left + temp_right + temp_top;
			p2[i] = temp_max;
		}

		if(i == line * (line+1) / 2){
			line += 1;
		}

		while(p1[i] != 0 && p1[i] % 2 == 0){
			p1[i] /= 2;
			p2[i] -= 1;
		}

	}
	
	line--;
	

	printf("%lld/%lld", p1[(line-1) * line / 2 + m + 1], (long long int)1 << p2[(line-1) * line / 2 + m + 1]);



	return 0;
}