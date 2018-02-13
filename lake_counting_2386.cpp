#include <iostream>

using namespace std;

int n, m;
const int row_max = 100;
const int col_max = 100;
char water[row_max][col_max];


void dfs(int y, int x){
    if(y < 0 || y > n || x < 0 || x > m || water[y][x]!='W')
        return;

    water[y][x] = '.';

    for(int dy = -1; dy <= 1; dy++){
        for(int dx = -1; dx <= 1; dx++){
             int pos_y = y + dy;
             int pos_x = x + dx;
             dfs(pos_y, pos_x);
        }
    }
}

int main(){
    int cnt = 0;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        scanf("%s", water[i]);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(water[i][j] == 'W'){
                dfs(i, j);
                cnt++;
            }
        }
    }

    cout << cnt << endl;
}
