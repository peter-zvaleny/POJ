#include <iostream>

using namespace std;

int fmin(float sum){
	int n = 0;
	while(sum > 0){
		n += 1;
		sum -= 1/(1.0 * (n + 1));
	}	
	return n;
}


int main(){
	float in;
	while(scanf("%f", &in) == 1){
		if(fmin(in) != 0){
			printf("%d card(s)\n", fmin(in));	
		}
	}
}
