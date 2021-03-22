#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <array>
using namespace std;
int dx[4] = {0, 1, 0, -1 }; // dir 0 : up, 1: right, 2: down 3 : left
int dy[4] = {-1, 0, 1, 0};
int original_map[10][10];
int min_sum = INT8_MAX;
int h, w;
vector <vector<int> >  camera;
int possible_dir[5][4][4] = {
    {{0, -1,-1,-1},{1,-1,-1,-1},{2,-1,-1,-1},{3,-1,-1,-1}},
    {{0, 2, -1,-1}, {1,3,-1,-1},{-2,-2,-2,-2}, {-2,-2,-2,-2}},
    {{0,1,-1,-1},{1,2,-1,-1},{2,3,-1,-1},{3,0,-1,-1}},
    {{0,1,2,-1},{1,2,3,-1},{2,3,4,-1},{3,0,1,-1}},
    {{0,1,2,3},{-2,-2,-2,-2},{-2,-2,-2,-2},{-2,-2,-2,-2}}
    
};
void go_strainght(int (&map)[10][10], int start_x, int start_y, int dir ){
    if(dir==-1) return;
    int cur = map[start_y][start_x];
    while(true){
        cout << "y: "<< start_y << " x: " << start_x << "=>"<<cur <<endl;
        if(cur == -1 || cur == 6) break;
        if(start_x>w || start_x < 1 || start_y > h || start_y < 1) break;
        else if(cur == 0) map[start_y][start_x] = 7;
        start_x += dx[dir];
        start_y += dy[dir];
        cur = map[start_y][start_x];
    }
}
void calc_and_update_min(int map[10][10]){
    int hide_counter = 0;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(map[i][j]==0) hide_counter++;
        }
    }
    min_sum = min(min_sum, hide_counter);
}
void print_map(int map[10][10]){
    for(int i=0; i<10;i++){
        for(int j=0;j<=10;j++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}
void solve(int idx, int map[10][10]){
    if(idx == camera.size()-1){
        calc_and_update_min(map);
        print_map(map);
        return;
    }
    int x, y, camera_type;
    y = camera[idx][0];
    x = camera[idx][1];
    camera_type = map[y][x];
    for(int i=0;i<4;i++){
        cout << idx << endl;
        int tmp[10][10];
        memcpy(tmp, map, sizeof(map));
        bool skip = false;
        for(int j=0;j<4;j++){
            if(possible_dir[camera_type][i][j]==-2){ break;skip = true;}
            else if(possible_dir[camera_type][i][j]==-1) continue;
            go_strainght(tmp, x, y, possible_dir[camera_type][i][j]);
        }
        if(skip) continue;
        solve(idx+1, tmp);


    }
    
}
int main(){
    cin >> h >> w;
    memset(original_map, -1, sizeof(original_map));
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >> original_map[i][j];
            if(original_map[i][j]!=0){
                vector <int> tmp;
                tmp.push_back(i);
                tmp.push_back(j);
                camera.push_back(tmp);
            }
        }
    }
    print_map(original_map);
    solve(0, original_map);
    cout << min_sum << endl;


}