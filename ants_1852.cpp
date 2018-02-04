#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int num;	
	scanf("%d\n", &num);
	for(int i = 0; i < num; i++){
		int pole;
		int n;
		scanf("%d%d", &pole, &n);
		int minTime = 0, maxTime = 0;
		for(int j = 0; j < n; j++){
			int left;
			scanf("%d", &left);	
			minTime = max(minTime, min(left, pole - left));			
			maxTime = max(maxTime, max(left, pole - left));
		}

	cout <<  minTime << " " << maxTime << endl;
	
	}
}
