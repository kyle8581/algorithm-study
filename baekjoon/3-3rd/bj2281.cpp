#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>
#include <math.h>
#include <limits.h>
using namespace std;
int name_len[1001] = {0};
int memo[1001][1001];
int n,m;
int min_sum = INT_MAX;
int exe_count = 0;
int solve(int i, int cur_sum, int space_left){
    if(space_left < name_len[i]) return 0;
    if(cur_sum > min_sum) return 0;

    if(i==n){
        if(cur_sum < min_sum) min_sum = cur_sum;
        return 0;
    }
    if(memo[i][space_left]!=0 && memo[i][space_left] <= cur_sum) return 0;
    exe_count ++;
    memo[i][space_left] = cur_sum;
    solve(i+1, memo[i][space_left] + pow((space_left-name_len[i]),2), m); // new line
    if(space_left - (name_len[i]+1)>0 
    
    
    ){
        solve(i+1 , memo[i][space_left], space_left - (name_len[i]+1)); // no new line
    }
    return 0;
}
void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}
int main(){
    init();
    cin >> n >> m;
    for(int i=1; i<n+1;i++){
        cin >> name_len[i];
    }
    solve(1, 0, m);
    cout << min_sum << endl;
    cout << "count : "<<exe_count << endl;
}