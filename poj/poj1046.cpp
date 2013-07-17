#include <iostream>
#include <cmath>
int r[16];
int g[16];
int b[16];

double dist(double i, double j, double k){
	return sqrt(pow((double)i,2)+pow((double)j,2)+pow((double)k,2));
}

int cal_distance(int x, int y, int z){
	double dis = 255*255*3;
	int target_i = -1;
	for(int i=0; i<16; i++){
		double temp = dist((double)(x-r[i]),(double)(y-g[i]), (double)(z-b[i]));
		if(temp < dis){
			dis = temp;
			target_i = i;
		}		
	}
	return target_i;
}


int main(){
	for(int i=0; i<16; i++){
		scanf("%d%d%d", &r[i], &g[i], &b[i]);	
	}
	int x,y,z;
	scanf("%d%d%d", &x,&y,&z);
	while(x!=-1 || y!=-1 || z!=-1){
		int k = cal_distance(x, y, z);
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n", x, y, z, r[k], g[k], b[k]);
		scanf("%d%d%d", &x,&y,&z);
	}

}