#include <iostream>

using namespace std;
long int a[15];

int main(){

	int k;
	cin>>k;
	for(int i=1; i<14; i++){
		a[i] = -1;	
	}

	while(k!=0){
		if(a[k] != -1){cout<<a[k]<<endl; cin>>k;continue;}

		int total;

		for(long int i=1;i<10000000;i++){
			total = 2*k;
			if(i%total <= k && i%total > 0){continue;}
			if(i%(k+1)!=0 && (i-1)%(k+1)!=0){continue;}
			int left = k;
			int cur_sum = i%total;
			bool find=false;
			while(cur_sum>=k+1 || cur_sum==0){						
				left--;
				if(left == 0){find = true; break;}		
				
				total--;	
				if(cur_sum>1){
					cur_sum = (cur_sum-1+i)%total;
				}
				else{
					cur_sum = i%total;	
				}

			}
			if(find == true){
				cout<<i<<endl;
				a[k] = i;
				break;
			}
		}


		cin>>k;
	}

	return 0;

}