#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
int map[12][27] = {0};
int possible_check[12][27] = {0};
int adjacent_count[12][27] = {0};
int other_adjacent_sum[12][27] = {0};
int mark[12][27] = {0};
int possible_count = 0;
float large_square_count = 0;
int get_adjacent_sum_with_range(int y, int x, int r){
    int adj_sum = 0;
    for(int i=y-r;i<y+r+1;i++){
        if(i<1 || i > 10) continue;
        // cout << i << endl;
        for(int j=x-r;j<x+r+1;j++){
            if(i==y && j==x) continue;
            if(possible_check[i][j]) adj_sum += adjacent_count[i][j];
        }
    }
    // cout << y << " " << x << " | sum :  " << adj_sum << endl;
    return adj_sum;
}
int check_should_mark(int y, int x){
    bool tied = false;
    if(mark[y][x]!=0) return -1;
    for(int i=y-1;i<y+2;i++){
        for(int j=x-1;j<x+2;j++){
            if((i==y && j==x) || (!possible_check[i][j])) continue;
            if(mark[i][j]==1){
                mark[y][x] = -1;
                return 0;
            }
            if(mark[i][j]==-1) continue;
            if(adjacent_count[i][j] < adjacent_count[y][x]) {
                mark[y][x] = -1;
                return 0;
            };
            if(adjacent_count[i][j] == adjacent_count[y][x]){
                tied = true;
                // bool fight_finished = false;
                // int r = 2;
                // while(!fight_finished){
                //     if(r+y>10 && y-r < 0 && x+r > 25 && x-r < 0){
                //         tied = true;
                //         fight_finished = true;
                //     }
                //     // cout << r << endl;
                //     int p1_sum, p2_sum;
                //     p1_sum = get_adjacent_sum_with_range(y,x,r);
                //     p2_sum = get_adjacent_sum_with_range(i,j,r);
                    
                //     if(p1_sum == p2_sum){
                //         r++;
                //     }
                    
                //     else if(p1_sum > p2_sum){mark[y][x]=-1;return 0;}
                //     else{
                //         fight_finished = true;
                //     }
                // }
            }
        }
    }
    if(tied){mark[y][x]=1;return 1 ;}
    mark[y][x] = 1;
    return 1;
}
int get_adjacent_sum(int y, int x){
    int sum_adjacent = 0;
    for(int i=y-1;i<y+2;i++){
        for(int j=x-1;j<x+2;j++){
            if(i==y && j==x) continue;
            if(possible_check[i][j]) sum_adjacent += adjacent_count[i][j];
        }
    }
    return sum_adjacent;

}

int count_neighbor(int y, int x){
    int neighbor_counter = 0;
    for(int i=y-1;i<y+2;i++){
        for(int j=x-1;j<x+2;j++){
            if(i==y && j==x) continue;
            if(possible_check[i][j]) neighbor_counter ++;
        }
    }
    adjacent_count[y][x] = neighbor_counter;
    return neighbor_counter;
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
    // 큰 사각형 들어갈 수 있을때 왼쪽 위 코너 좌표에 표시함
    for(int i=1;i<h+1;i++){
        for(int j=1;j<w+1;j++){
            if(map[i][j] && map[i+1][j] && map[i][j+1] && map[i+1][j+1]){
                possible_check[i][j] = 1;
                possible_count ++;
           
            }
        }
    }
    // cout << "check 1\n";
    // 주변에 가능성 있는 점의 개수 세서 저장
    for(int i=1;i<h+1;i++){
        for(int j=1;j<w+1;j++){
            if(possible_check[i][j]){
                count_neighbor(i,j);
           
            }
        }
    }
    // cout << "check 2\n";

    for(int i=1;i<h+1;i++){
        for(int j=1;j<w+1;j++){
            if(possible_check[i][j]){
                other_adjacent_sum[i][j] = get_adjacent_sum(i,j);
           
            }
        }
    }
    // cout << "check 3\n";

    for(int i=1; i<h+1;i++){
        for(int j=1;j<w+1;j++){
            if(possible_check[i][j]){
                int result = check_should_mark(i, j);
                if(result==1) large_square_count += 1;
                if(result==1 or result==-1) possible_count--;
                // if(result==-1) large_square_count += 0.5;
                // cout << i << " " << j << ": "<< result <<endl;

                

            }
        }
    }
    // for(int i=0;i<12;i++){
    //     for(int j=0;j<27;j++){
    //         cout << mark[i][j];
    //     }
    //     cout << endl;
    // }
    int w_c = 0;
    while(possible_count > 0){
        // cout << possible_count << endl;
        for(int i=1; i<h+1;i++){
        for(int j=1;j<w+1;j++){
            if(possible_check[i][j] && mark[i][j]==0){
                int result = check_should_mark(i, j);
                if(result==1) large_square_count += 1;
                if(result==1 or result==0) possible_count--;
                // if(result==-1) large_square_count += 0.5;
                // cout << i << " " << j << ": "<< result <<endl;

                

                }
            }
        }   
        // for(int i=0;i<12;i++){
        // for(int j=0;j<27;j++){
        //     cout << mark[i][j];
        // }
        // cout << endl;
    // }
        w_c ++;
        if(w_c==10)break;
    }
    for(int i=0;i<12;i++){
        for(int j=0;j<27;j++){
            if(mark[i][j]==0 or mark[i][j] == 1) cout << " "<<mark[i][j];
            else cout << mark[i][j];
        }
        cout << endl;
    }
    cout << "sq: " <<large_square_count << endl;
    large_square_count = ceil(large_square_count);
    int ans = 0;
    ans += w * h - 4 * large_square_count;
    ans += 16 * large_square_count;
    cout << ans << endl;

}

