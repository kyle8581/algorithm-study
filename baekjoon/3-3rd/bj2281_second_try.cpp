#include <iostream>
#include <cstring>//memset
#include <algorithm>//min
using namespace std;

int n, m;
int memo[1001][1001];
int name[1001];
int solve(int idx, int len){
    if(idx>n) return 0;
    int& res = memo[idx][len];
    if(res!= -1) return res;
    res = (m - len + 1)*(m - len + 1) + solve(idx+1, name[idx]+1);
    if(len+name[idx]<=m){
        res = min(res, solve(idx+1, len + name[idx]+1));
    }
    return res;


}
int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> name[i];
    memset(memo, -1, sizeof(memo));
    cout << solve(2, name[1]+1) << endl;
    return 0;
}