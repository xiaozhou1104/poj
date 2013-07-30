#include <cstdio>

void swap_two(long long int& x, long long int& y){
	long long int temp = x;
	x = y;
	y = temp;
};

long long int Gcd(long long int a, long long int b){

	if(b == 0)
		return a;

	return Gcd(b, a%b);

}

long long int exGcd(long long int a, long long int b, long long int& x, long long int& y){

	long long int d = 0;
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}
	
	long long int temp_x;
	long long int temp_y; 
	d = exGcd(b, a%b, temp_x, temp_y);
	
	x = temp_y;
	y = temp_x - a / b * temp_y;

	return d;
}


int main(){

	long long int x,y,m,n,l;
	scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l);
	bool meet = true;
	if(m == n){
		meet = false;
	}
	else if(n > m){
		swap_two(m,n);
		swap_two(x,y);
	}
	long long int temp_gcd = Gcd(m-n, l);
	if(((y-x) % temp_gcd) != 0)
		meet = false;
	if(meet == false)	
		printf("Impossible\n");
	else{
		long long int exgcd_a = (m-n) / temp_gcd;
		long long int exgcd_n = (y-x) / temp_gcd;
		l = l / temp_gcd;

		long long int exgcd_x,exgcd_y;
		long long int exgdc_d = exGcd(exgcd_a,l,exgcd_x,exgcd_y);
		exgcd_x *= exgcd_n;

		if(exgcd_x < 0){
			while(exgcd_x < 0){
				exgcd_x += l;
			}
		}
		else{
			while(exgcd_x - l > 0){
				exgcd_x -= l;
			}
		}

		printf("%lld", exgcd_x);
	
	}

	//long long int x1,x2,x3,x4;
	//int x5;
	//x1 = 11;
	//x2 = 5;
	//x5 = exGcd(x1,x2,x3,x4);

	//printf("%lld\n%lld\n%d\n", x3,x4,x5);

	return 0;
}