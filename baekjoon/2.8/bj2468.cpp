#include <iostream>
#include <string.h>
using namespace std;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

int g[102][102];

int check[102][102];
void dfs(int x, int y){
    // cout << x << " " << y << endl;
    if(check[x][y]==0) return;
    else{
        check[x][y] = 0;
        for(int i=0;i<4;i++){
            dfs(x+dx[i], y+dy[i]);

        }
    }
}
int check_safe_region(int h, int w){
    int counter = 0;
    for(int i=0; i<102; i++){
        memset(check[i], 0, 102);
    }
    // cout << "check fill" << endl;
    for(int i=1;i<w+1;i++){
        for(int j=1;j<w+1;j++){
            if(g[i][j] > h) check[i][j] = 1;
            
        }
    }
    // cout << "check fill finished" << endl;

    for(int i=1;i<w+1;i++){
        for(int j=1;j<w+1;j++){
            if(check[i][j] == 1) {
                // cout << "dfs " << counter << endl;
                dfs(i, j);
                counter += 1;
            }
            
        }
    }
   
    return counter;


}
int main(){
    int w, min_h, max_h, max_count;
    cin >> w;
    min_h = 101;
    max_h = 0;
    max_count = 1;
    for(int i=0; i<102; i++){
        memset(g[i], 0, 102);
    }
    for(int i=1;i<w+1;i++){
        for(int j=1;j<w+1;j++){
            int h;
            cin >> h;
            g[i][j] = h;
            if(h<min_h) min_h = h;
            if(h > max_h) max_h = h;

        }
    }
    for(int i=min_h;i< max_h+1;i++ ){
        int c = check_safe_region(i, w);
        // cout << i << " count : " << c << endl; 
        if(c > max_count) max_count = c;
    }
    cout << max_count << endl;
}