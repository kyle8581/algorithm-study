#include <iostream>
using namespace std;
int chess[50][50];
int w, h;
int check(int x_start, int y_start, int worb){
    int count = 0;
    for(int i=y_start; i< y_start+8; i++){
        for(int j=x_start;j<x_start+8;j++){
            int cur;
            if((i+j)%2 == 0) cur = worb;
            else cur = worb * -1;
            if(chess[i][j] != cur) count +=1;
            // cout << cur;
        }
        // cout << endl;
    }  
    // cout << x_start << " " << y_start << " " << count << endl; 
    return count;

}
int main(){
    int min_change = 2500;
    cin >> h >> w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            char c;
            cin >> c;
            if(c == 'W') chess[i][j] = 1; // white = 1
            else chess[i][j] = -1; // black = -1
        }
    }

    for(int i=0;i<w-7;i++){
        for(int j=0;j<h-7;j++){
            int count;
            count = min(check(i,j,1),check(i,j,-1));
            min_change = min(count, min_change);
        }
    }
    cout << min_change << endl;

}