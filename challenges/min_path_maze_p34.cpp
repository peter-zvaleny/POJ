#include <iostream>
#include <queue>
using namespace std;

const int row_max = 100, col_max = 100;
char maze[row_max][col_max];

class node{
public:  int y;
         int x;
         int dist; 

public: node(int yin, int xin, int distin){
    y = yin;
    x = xin;
    dist = distin;    
  }
};


void printNode(node n){
    cout << "y: " << n.y << ", x: " << n.x << ", dist: " << n.dist << endl;
}


int dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1};

int main(){
    freopen("min_path_maze_p34_test.txt", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){ 
        scanf("%s", maze[i]);
    }

    for(int i = 0; i < n; i++){
        printf("%s\n", maze[i]);
    }

    queue<node> q;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(maze[i][j] == 'S'){
                q.push(node(i, j, 0));
            }
        }
    }

    while(q.size()){
        node cur = q.front();
        cout << "Node currently visiting: " << endl;
        printNode(cur);
        q.pop();
        maze[cur.y][cur.x] = cur.dist;

        for(int i = 0; i < 4; i++){
            int pos_y = cur.y + dy[i];
            int pos_x = cur.x + dx[i];
          
            if(pos_y < n && pos_y >= 0 && pos_x < m && pos_x >=0 && maze[pos_y][pos_x] == '.'){
                cout << "item(s) to be pushed: (" << pos_y << ", " << pos_x << ", " << cur.dist + 1 << ")" <<  endl;
                q.push(node(pos_y, pos_x, cur.dist + 1));
            }

            if(maze[pos_y][pos_x] == 'G'){
		cout << "The total distance from S to G: " << cur.dist + 1 << endl;
		return 0;  
	    }
        } 

    } 
}


