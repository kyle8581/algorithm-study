#include <iostream>
using namespace std;
int main(){
    int n;
    int scores[505][505] = {0};
    int  save[505][505] = {0};
    cin >> n;
    if(n==1){
        int ans;
        cin >> ans;
        cout << ans << endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cin >> scores[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            save[i][j] = max(save[i-1][j], save[i-1][j-1]) + scores[i][j];
        }

    }
    int max_num = 0;
    for(int i=1;i<=n;i++){
        if(max_num<save[n][i]){
            max_num = save[n][i];
        }
    }
    cout << max_num << endl;


}
// 
