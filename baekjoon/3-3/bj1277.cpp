#include <iostream>
#include <string.h>
#include <queue>
#include <cmath>
using namespace std;
int N, W;
float limit;
float dist[1001][1001];
float min_dist[1001];
int pos[1001][2];
typedef pair<float, int> pi;
int main(){
    memset(min_dist, -1.f, sizeof(min_dist));
    memset(dist, INT16_MAX, sizeof(dist));
    
    cin >> N >> W;
    cin >> limit;
    for(int i=1;i<N+1;i++){
        cin >> pos[i][0] >> pos[i][1];

    }
    float cur_dist;
    for(int i=1;i<N+1;i++){
        for(int j=1;j<N+1;j++){
            cur_dist = sqrt((pos[i][0]-pos[j][0])*(pos[i][0]-pos[j][0]) + (pos[i][1]-pos[j][1])*(pos[i][1]-pos[j][1]));
            dist[i][j] = cur_dist;
            dist[j][i] = cur_dist;
        }
    }
    int v1,v2;
    for(int i=0;i<W;i++){
        cin >> v1 >> v2;
        dist[v1][v2] = 0;
        dist[v2][v1] = 0;
    }
    cout << "dist to N "<< min_dist[N] << endl;
    priority_queue<pi, vector<pi>, greater<pi> > pq;
    pq.push(make_pair(0, 1));
    while(!pq.empty()){
        pi cur = pq.top();
        cout << cur.first << " " << cur.second << endl;
        pq.pop();
        if(min_dist[cur.second] != -1.f){cout << "c\n";continue;}
        min_dist[cur.second] = cur.first; // save distance
        for(int i=1;i<N+1;i++){
            cout << i << endl;
            if(min_dist[i]!= -1 || dist[cur.second][i] > limit) continue;
            cout << "pair pushed " << i << endl; 
            pq.push(make_pair(dist[cur.second][i]+cur.first, i));
        }


    }
    cout << min_dist[N] << endl;

}