#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>
#include <math.h>
using namespace std;

int main(){
    map<string, double> tree_count;
    double total = 0;
    string s;
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    while(getline(cin,s)){
        if(s.length()==0) break;
        if(tree_count.count(s)==0) tree_count[s] = 1;
        else tree_count[s] += 1;
        total += 1;
    }
    // cout << fixed;
    // cout.precision(4);
    map<string, double> ::iterator it;
    for(it = tree_count.begin();it!=tree_count.end();it++){
       
        cout << it->first << " " << round((double)it->second/(double)total * 100.0 * 10000.0)/ 10000.0<< endl;
    }
}


