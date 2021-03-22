#include <iostream>
#include <functional>
#include <queue>

using namespace std;

int main(){

	// priority_queue
	priority_queue< long long int, vector<long long int>, greater<long long int> > pq;
    int n, m;
    cin >> n;
    cin >> m;
    for(int i=0;i<n;i++){
        long long int v;
        cin >> v;
        pq.push(v);
    }
    for(int i=0;i<m;i++){
        long long int sum = 0;
        sum += pq.top();
        pq.pop();
        sum+= pq.top();
        pq.pop();
        pq.push(sum);
        pq.push(sum);
        // cout << pq.top() << endl;
	
    }
    long long int total_sum=0;
    while (!pq.empty())
    {
        /* code */
        total_sum += pq.top();
        pq.pop();
    }
    
    cout << total_sum<< endl;

}