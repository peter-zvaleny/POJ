//ref: http://blog.csdn.net/niushuai666/article/details/6975760
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

char newmap(char inchar);
// record of phone numbers
char phone[80000][9];
char num[200];
map<string, int> cntmap;

// map from chars to numbers
char newmap(char inchar){
    if(inchar == 'A' || inchar == 'B' || inchar == 'C')
        return '0' + 2;

    else if(inchar == 'D' || inchar == 'E' || inchar == 'F')
        return '0' + 3;

    else if(inchar == 'G' || inchar == 'H' || inchar == 'I')
        return '0' + 4;

    else if(inchar == 'J' || inchar == 'K' || inchar == 'L')
        return '0' + 5;

    else if(inchar == 'M' || inchar == 'N' || inchar == 'O')
        return '0' + 6;

    else if(inchar == 'P' || inchar == 'R' || inchar == 'S')
        return '0' + 7;

    else if(inchar == 'T' || inchar == 'U' || inchar == 'V')
        return '0' + 8;

    else if(inchar == 'W' || inchar == 'X' || inchar == 'Y')
        return '0' + 9;

    else
        return inchar;
}


int main(){
    int n; //# phone numbers
    //freopen("test.txt", "r", stdin);
    scanf("%d", &n);

    int pj = 0;
    bool flag = false;

    for(int pi = 0; pi < n; pi++){
         scanf("%s", num);
         for(int i = 0; num[i]!='\0'; i++){
             if(pj == 3){
                 phone[pi][pj++] = '-';
             }
             if(num[i] >= '0' && num[i] <= '9'){
                 phone[pi][pj] = num[i];
             }else if(num[i] >= 'A' && num[i] <= 'Z'){
                 phone[pi][pj] = newmap(num[i]);
             }else if(num[i] == '-'){
                 continue;
             }
             pj++;
	      }

        pj = 0;
    }

    for(int i = 0; i < n; i++){
        cntmap[phone[i]]++;
    }

    for(map<string, int>::iterator  it = cntmap.begin(); it != cntmap.end(); it++){
        if(it->second >1){
            flag = true;
            cout << it->first << " " << it->second << endl;
        }
    }
    if(!flag){
        printf("No duplicates.\n");
    }
}
