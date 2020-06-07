#include <bits/stdc++.h>
using namespace std;

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

/* recursive solution

void dfsTraverse(vector<int> g[], vector<int> *v, int visit[], int i)
{
    if(visit[i]==0)
        v->push_back(i);
    visit[i]=1;
    for(auto it=g[i].begin();it!=g[i].end();it++)
    {
        if(visit[*it]==0)
            dfsTraverse(g,v,visit,*it);
    }
    
}

vector <int> dfs(vector<int> g[], int N)
{
    
    // Your code here
    vector<int> vec;
    int visit[N]={0};
    dfsTraverse(g,&vec,visit,0);
    return vec;
}
*/
int main()
{
    int T;
    cin>>T;
    while(T--)
    {

        int N, E;
        cin>>N>>E;
        
        vector<int> g[N];
        bool vis[N];
        
        memset(vis, false, sizeof(vis));
        
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector <int> res = dfs(g, N);
        for (int i = 0; i < res.size (); i++)
            cout << res[i] << " ";
        cout<<endl;

    }
}
