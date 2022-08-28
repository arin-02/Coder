#include<bits/stdc++.h>
using namespace std;
// topological sort Directed acyclic graph mei hee lg skta jisme hr node agli ke peeche hee milega.. jaise 0 se phele hee aega 5 ,,3 se phele 2 aege kyuki 2->3 hai

void topodfs(int x,vector<vector<int>> &adj,vector<int> &vis,stack<int> &st)
{
    vis[x]=1;
    for(auto it:adj[x])
    {
        if(!vis[it])
        {
            topodfs(it,adj,vis,st);
        }
    }
    st.push(x);
}
int main()
{
    int V,E;
    cin>>V>>E;
    vector<vector<int>> adj(V,vector<int>());
    vector<int> vis(V,0);
    stack<int> st;
    for(int i=0;i<E;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
      
    }   
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
            topodfs(i,adj,vis,st);
        }
    }
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}
// 6 6
// 5 0
// 4 0
// 5 
// 2
// 2 3
// 3 1
// 4 1