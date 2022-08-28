// assign weight 1 if no weight is specified
#include<bits/stdc++.h>
using namespace std;

void topo(vector<vector<pair<int,int>>> &adj,vector<int> &vis,stack<int> &st,int x)
{
    vis[x]=1;
    for(auto it:adj[x])
    {
        if(!vis[it.first])
        {
            topo(adj,vis,st,it.first);
        }
    }
    st.push(x);
    
}

void shortestDistanceWeighted(vector<vector<pair<int,int>>> &adj,stack<int> &st,int src,int V)
{
    vector<int> vis(V+1,0);
   for(int i = 0; i <= V; i++)
   {
        if(!vis[i])
        {

        topo(adj,vis,st,i);
        }
   }
   stack<int> ss=st;
   cout<<"topological stack order :- "<<endl;
   while(!ss.empty())
   {
    cout<<ss.top()<<" " ;
    ss.pop();
   }
   cout<<endl;

    vector<int> dist(V+1,1e9);
    
    dist[src]=0;


    while(!st.empty())
    {
        int y=st.top();
        // cout<<y<<endl;
        st.pop();
        // cout<<dist[y]<<endl;
        if(dist[y]!= 1e9)
        {
            for(auto it:adj[y])
            {
                if(dist[y]+it.second<dist[it.first])
                {
                    dist[it.first]=dist[y]+it.second;
                }
            }
        }
    }
    cout<<"Distance array:- "<<endl;
    for(int i=0;i<dist.size();i++)
    {
        cout<<dist[i]<<" ";
    }



}


int main()
{
    int V,E;
    cin>>V>>E;
    vector<vector<pair<int,int>>> adj(V+1,vector<pair<int,int> >());
    
   

    for(int i=0;i<E;i++)
    {
        int x,y,wt; 
        cin>>x>>y>>wt;
        adj[x].push_back({y,wt});
        
    }   
   
    vector<int> dist(V,1e9);
    int src=0;
    stack<int> st;
    dist[src]=0; //src node ko 0 
    
    shortestDistanceWeighted(adj,st,src,V);

    
    
   
   
    
}
// 5 7
// 0 1 2
// 0 4 1
// 1 2 3
// 4 2 2
// 2 3 6
// 4 5 4
// 5 3 1