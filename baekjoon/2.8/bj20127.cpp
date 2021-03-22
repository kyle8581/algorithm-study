#include <iostream>
using namespace std;
int get_direction(int prev, int cur){
    if(prev < cur) return 1;
    else if(prev > cur){return -1;}
    else return 0;
}
int main(){
    int n;
    cin >> n;
    if(n==1){cout << -1 << endl; return 0;}
    int change_count = 0;
    int change_index;
    int current_direction;
    int cur,prev;
    cin >> prev;
    cin >> cur;
    current_direction = get_direction(prev, cur);
    for(int i=0;i<n-2;i++){
        prev = cur;
        cin >> cur;
        int direction = get_direction(prev, cur);
        // cout << current_direction << " " << direction << endl;
        if (direction * current_direction == -1){
            change_count += 1;
            change_index = i+2;
            current_direction *= -1;
            if(change_count > 1){cout << -1 << endl; return 0;}
        }
        else if(direction !=0 && current_direction ==0 ){
            current_direction = direction;
        }
        else if (direction ==0 && current_direction !=0 ){
            current_direction = current_direction;
        }
        else if(direction == 0){
            current_direction = 0;
        }
        
    }
    if(change_count == 0){
        cout << 0 << endl;
    }
    else{

    cout << change_index << endl;
    }

}
