#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>
#include <math.h>
using namespace std;

int main(){
    int n, x;
    long long int max_sum;
    cin >> n;
    vector <int> numbers;
    // input
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        numbers.push_back(tmp);
    }
    // sort in ascending order
    sort(numbers.begin(), numbers.end());
    if(numbers[0]!=1){
        cout << 1 << endl;
        return 0;
    }
    max_sum = numbers[0];
    for(int i=1;i<n;i++){
        if(max_sum+1 < numbers[i]) {cout << max_sum + 1 << endl; return 0;}
        max_sum += numbers[i];
    }
    cout << max_sum+1 << endl;


    return 0;
}