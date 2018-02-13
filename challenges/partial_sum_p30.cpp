/*
部分和问题 from 《挑战程序设计竞赛》p30
(add record of numbers part)
-----------------
Problem Statement:
给定整数a1, a2, ..., an, 判断是否可以从中选出若干数，使他们的和恰好为k.
------------
限制条件:
1<= n <= 20
-10^8 <= ai <= 10^8
-10^8 <= k <= 10^8
-------------
Sample Input:
4
1 2 4 7
13
Sample Output:
Yes (13 = 2 + 4 + 7)
*/

#include <iostream>

using namespace std;

const int MAX_N = 10;
int k, n;
int cnt = 0;
int a[MAX_N];
int res[MAX_N];

bool dfs(int i, int sum){
	if(i == n) return sum == k;
	if(dfs(i + 1, sum)) return true;
	if(dfs(i + 1, sum + a[i])){
		res[cnt++] = a[i];
		return true;
	}
	return false;	
}


void solve(){
	if(dfs(0, 0)){
		printf("Yes");
		cout << " (" << k << " = ";
		for(int i = cnt - 1; i > 0; --i){
			printf("%d + ", res[i]);
		} 
		printf("%d",res[0]);
		cout << ")" << endl;
	}else{
		printf("No");
	}	
}


int main(){
	freopen("partial_sum_30_test.txt","r",stdin);
	while(scanf("%d",&n) == 1){
		for(int i = 0; i < n; ++i){
			scanf("%d", &a[i]);
		}
		scanf("%d", &k);
		solve();
	}
}
