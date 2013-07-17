#include <iostream>
#include <vector>
#include <set>

using namespace std;


int N,K;
int false_count=0;
int similar[100000]={-1};
int eat_front[100000]={-1};
int eat_next[100000]={-1};



int main(){

	scanf("%d%d", &N, &K);
	
	int d,x,y;
	for(int i=0;i<K;i++){
		scanf("%d%d%d", &d,&x,&y);
		if(x>N || y>N){false_count++; continue;}
		if(d == 1){
			if(eat_front[x] != y && eat_next[x] != y){
				

			}
		}
	}

	printf("%d\n", false_count);




	return 0;

}