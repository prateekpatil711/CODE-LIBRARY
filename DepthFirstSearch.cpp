#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100000];
int vis[100000]={0};

void dfs(int node)
{
    stack<int> s;
    s.push(node);
    while(!(s.empty()))
    {
        int x=s.top();
        s.pop();
        if(vis[x]==0) cout<<x<<" ";
        vis[x]++;
        for(auto it:adj[x])
        {
            if(!(vis[it]))
            {
                s.push(it);
            }
        }
    }
}