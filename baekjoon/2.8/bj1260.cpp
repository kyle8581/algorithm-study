#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Node{
    public:
        int n;
        vector<Node> next;
        Node(int n){
            n = n;
        }
};
vector <Node> g;
int b_visited[1001] = {0,};
int d_visited[1001] = {0,};
queue <int> bfs_stack;
void DFS(int s){

}
void BFS(int s){
    bfs_stack.push(s);
    while(bfs_stack.size()!=0){
        int cur = bfs_stack.front();
        bfs_stack.pop();
        b_visited[cur] = 1;
        for(int i=0;i<g[s].next.size();i++){
            if(b_visited[g[s].next[i].n]==0){
                cout << g[s].next[i].n << " ";
                bfs_stack.push(g[s].next[i].n);

            }

        }
        cout << endl;

    }
    

}
int main(){
    int M, N, V;
    cin >> M >> N >> V;
    Node start(0);
    g.push_back(start);
    for(int i=0;i<N; i++){
        Node n(i+1);
        g.push_back(n);
    }
    for(int i=0;i<N;i++){
        int x,y;
        cin >> x >> y;
        g[x].next.push_back(g[y]);
        g[y].next.push_back(g[x]);


    }
    BFS(V);
     

}