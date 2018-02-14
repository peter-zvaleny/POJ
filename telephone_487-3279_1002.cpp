//ref:
//1.  http://blog.csdn.net/niushuai666/article/details/6975760
//2. http://poj.org/showmessage?message_id=171227
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int newmap(char inchar);
// record of phone numbers
map<int, int> cntmap;
char num[200];
// map from chars to numbers
int nummap[] =
{
    2, 2, 2,
    3, 3, 3,
    4, 4, 4,
    5, 5, 5,
    6, 6, 6,
    7, 0, 7, 7,
    8, 8, 8,
    9, 9, 9
};

int main(){
    int n; //# phone numbers
    // freopen("test.txt", "r", stdin);
    scanf("%d", &n);
    bool flag = false;

    for(int pi = 0; pi < n; pi++){
         scanf("%s", num);
         int phone = 0;
         for(int i = 0; num[i]; i++){
             if(num[i] >= '0' && num[i] <= '9'){
                phone = 10 * phone + num[i] - '0';
             }else if(num[i] >= 'A' && num[i] <= 'Z'){
                 phone = 10 * phone + nummap[num[i] - 'A'];
             }
	      }
      cntmap[phone]++;
    }

    for(map<int, int>::iterator  it = cntmap.begin(); it != cntmap.end(); it++){
        if(it->second >1){
            flag = true;
            printf("%03d-%04d %d\n", it->first / 10000, it->first % 10000, it->second);
        }
    }
    if(!flag){
        printf("No duplicates.\n");
    }
}
