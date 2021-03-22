#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int possible[12][27] = {0};
int visited[12][27] = {0};
int selected_status[12][27] = {0};
int notselected_status[12][27] = {0};
int map[12][27] = {0};
vector< vector<int> > possible_vector;
vector< vector<int> > connected;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int possible_count = 0;
// void fetch_max(int x, int y){
//     vector<int> other_max;
//     other_max.push_back(selected_status[])
// }
void get_connected(int y, int x){
    if(!possible[y][x]) return;
    possible_count --;
    vector<int> cor;
    cor.push_back(y);
    cor.push_back(x);
    connected.push_back(cor);
    get_connected(y, x+1);
    if(possible[y+1][x]) get_connected(y+1,x);
    else get_connected(y+1, x+1);
}
bool neighborhood_check(int y, int x){
    if(possible[y-1][x-1] || possible[y-1][x] || possible[y-1][x+1] || possible[y][x-1]) return true;
    else return false;
}
int main(){
    int h, w;
    cin >> h >> w;
    for(int i=0;i<h;i++){
        string s;
        cin >> s;
        for(int j=0;j<w;j++){
            if(s[j]=='.') map[i+1][j+1] = 1; // 빈공간에 1
        }
    }
    // cout << "input end\n";
    // 큰 사각형 들어갈 수 있을때 왼쪽 위 코너 좌표에 표시함
    for(int i=1;i<h+1;i++){
        for(int j=1;j<w+1;j++){
            if(map[i][j] && map[i+1][j] && map[i][j+1] && map[i+1][j+1]){
                possible[i][j] = 1;
                vector<int> cor;
                cor.push_back(i);
                cor.push_back(j);

                possible_vector.push_back(cor);
                possible_count ++;
            }
        }
    }
    // for(int i=0;i<12;i++){
    //     for(int j=0;j<27;j++){
    //         cout << possible[i][j];
    //     }
    //     cout << endl;
    // }
    // cout << "square mark end\n";
    int square_counter = 0;
    
   for(int v=0;v<possible_vector.size();v++){
        int x = possible_vector[v][1];
        int y = possible_vector[v][0];
        if(visited[y][x]==1){
            // assert(!possible_vector.empty());
            // possible_vector.erase(possible_vector.begin());
            // possible_vector.pop_back();
            continue;
        }
        int prev_max = 0;
        int prev_min = 0;
        connected.clear();
        get_connected(y, x);
        for(int l=0;l<connected.size();l++){
            int i=connected[l][0];
            int j=connected[l][1];
            // visited[i][j] = 1;
            vector<int> other_x;
            vector<int> other_o;
            int other_x_min, other_o_max;
            for(int k=j-1;k<j+2;k++){
                if(possible[i-1][k]){
                    other_o.push_back(selected_status[i-1][k]);
                    other_x.push_back(notselected_status[i-1][k]);
                }
            }
            if(possible[i][j-1]){
                other_o.push_back(selected_status[i][j-1]);
                other_x.push_back(notselected_status[i][j-1]);
            }
            // cout << "right before calc max\n";
            if(other_o.empty())other_o_max=prev_min;
            else other_o_max = *max_element(other_o.begin(), other_o.end());
            // cout << "max\n";
            // if(other_x.empty()) other_x_min = prev_min + 1;
            // else other_x_min = *min_element(other_x.begin(), other_x.end()) + 1;
            other_x_min = prev_max + 1;
            cout << "y: "<< i << " x: " << j <<" min : " << other_x_min << " max : " << other_o_max << endl;
            if(other_x_min > other_o_max) {
                square_counter ++;
                

            }
            selected_status[i][j] = other_x_min;
            notselected_status[i][j] = other_o_max;
            prev_max = other_o_max;
            prev_min = other_x_min;
        }
    }
    
    // for(int i=1;i<h+1;i++){
    //     for(int j=1;j<w+1;j++){
    //         if(possible[i][j]==0) continue;
    //         // cout << i << " " << j << endl;
    //         if(!neighborhood_check(i,j)){
    //             prev_max = 0;
    //             prev_min = 0;
    //         }
    //         vector<int> other_x;
    //         vector<int> other_o;
    //         int other_x_min, other_o_max;
    //         for(int k=j-1;k<j+2;k++){
    //             if(possible[i-1][k]){
    //                 other_o.push_back(selected_status[i-1][k]);
    //                 other_x.push_back(notselected_status[i-1][k]);
    //             }
    //         }
    //         if(possible[i][j-1]){
    //             other_o.push_back(selected_status[i][j-1]);
    //             other_x.push_back(notselected_status[i][j-1]);
    //         }
    //         // cout << "right before calc max\n";
    //         if(other_o.empty())other_o_max=prev_min;
    //         else other_o_max = *max_element(other_o.begin(), other_o.end());
    //         // cout << "max\n";
    //         // if(other_x.empty()) other_x_min = prev_min + 1;
    //         // else other_x_min = *min_element(other_x.begin(), other_x.end()) + 1;
    //         other_x_min = prev_max + 1;
    //         cout << "min : " << other_x_min << " max : " << other_o_max << endl;
    //         if(other_x_min > other_o_max) {
    //             square_counter ++;
                

    //         }
    //         selected_status[i][j] = other_x_min;
    //         notselected_status[i][j] = other_o_max;
    //         prev_max = other_o_max;
    //         prev_min = other_x_min;
    //     }
    // }
    int ans = 0;
    cout << square_counter << endl;
    ans += w * h - 4 * square_counter;
    ans += 16 * square_counter;
    cout << ans << endl;

}