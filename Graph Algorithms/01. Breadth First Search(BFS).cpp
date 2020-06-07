
#include <bits/stdc++.h>

using namespace std;

vector <int> bfs(vector<int> g[], int N);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        vector<int> adj[N];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        vector <int> res = bfs(adj, N);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        cout << endl;
    }
}
/* Function to do BFS of graph
*  g[]: adj list of the graph
*  N : number of vertices
*/
vector <int> bfs(vector<int> g[], int N) {
    bool visit[N]={0};
    queue<int>q;
    vector<int> v;
    q.push(0);
    visit[0]=true;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        v.push_back(x);
        for(auto i: g[x])
        {
            if(!visit[i])
            {
                visit[i]=true;
                q.push(i);
            }
        }
    }
    return v;
}
