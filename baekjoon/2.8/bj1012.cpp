#include <iostream>
#include <vector>
using namespace std;

int field[52][52];
int adjacent_vec[4][2]= {{-1,0}, {1,0}, {0,1},{0,-1}};


// up down right left
void initialize_field_to_zero(){ // memset()
    for(int i=0; i<52;i++){
        for(int j=0;j<52;j++){
            field[i][j] = 0;
        }
    }
}
void DFS(int x, int y){
    if(field[x][y] == 1){
        field[x][y] = 0;
        for(int i=0;i<4;i++){// 위 아래 왼쪽 오른쪽 
            DFS(adjacent_vec[i][0]+x, adjacent_vec[i][1]+y);
        }

    }
    else{
        return;
    }
}
void solve(){
    int width, height, k;
    int counter = 0;
    cin >> width >> height>> k;
    for(int i=0;i<k;i++){
        int x,y;
        cin >> x >> y;
        field[x+1][y+1] = 1; 
    }
    for(int i=0; i<52;i++){
        for(int j=0;j<52;j++){
            if(field[i][j]==1){
                counter += 1;
                DFS(i, j);

            }
        }
    }
    cout << counter << endl;




    
}
int main(){
  
    int number_of_testcase;
    cin >> number_of_testcase;
   
    for(int i=0;i<number_of_testcase;i++){
        solve();
        initialize_field_to_zero();
    }
}