#include <iostream>
using namespace std;

int main(){
    int n;
    int scores[1000];
    int save[1000];
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> scores[i];
    }
    save[0] = scores[0];
    save[1] = scores[0] + scores[1];
    save[2] = max(scores[0]+scores[2] , scores[1]+scores[2]);
    for(int i=3;i<n;i++){
        save[i] = max(save[i-2]+ scores[i], save[i-3]+scores[i-1]+scores[i]);
    }
    cout << save[n-1] << endl;
    
}