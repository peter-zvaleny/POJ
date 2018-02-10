#include <iostream>

using namespace std;

int main(){
	float sum = 0;
	float cur;
	for(int i = 0; i < 12; i++){
	    scanf("%f", &cur);
		sum += cur;
	}

	cout << "$" << sum/(12 * 1.0) << endl;
}


