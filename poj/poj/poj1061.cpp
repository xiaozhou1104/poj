#include <iostream>

int main(){


	long long int x,y,m,n,l;
	while(scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l)!=EOF){
	//scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l);

	bool meet = false;
	long long int count = 0;
	if(m - n == 0){
		printf("Impossible\n");	
	}
	else if(m > n){
		if(x < y && (y-x)%(m-n) == 0){
			meet = true;
			count = (y-x)/(m-n);
		}
		else{
			for(int i=1; i<=m-n; i++){
				if((y-x+i*l) % (m-n) == 0){
					count = (y - x + i * l) / (m - n);
					meet = true;
					break;
				}
			}
		}
	}
	else{
		if(y < x && (x-y)%(n-m) == 0){
			meet = true;
			count = (x-y)/(n-m);
		}
		else{
			for(int i=1; i<=n-m; i++){
				if((x - y + i * l) % (n - m) == 0){
					count = (x - y + i * l) / (n - m);
					meet = true;
					break;
				}
			}	
		}
	}

	if(meet == true){
		printf("%lld\n", count);
	}
	else{
		printf("Impossible\n");	
	}
}

	return 0;
}