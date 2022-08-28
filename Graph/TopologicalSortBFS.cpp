#include<bits/stdc++.h>
using namespace std;
// topological sort Directed acyclic graph mei hee lg skta jisme hr node agli ke peeche hee milega.. jaise 0 se phele hee aega 5 ,,3 se phele 2 aege kyuki 2->3 hai

// indegree= kitni edge uske andr aa rhi hai...

vector<int> v;
void topoBFS(vector<vector<int>> &adj,vector<int> &indegree)
{
    queue<int> q;
    for(int i=0;i<indegree.size();i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }

    }
    while(!q.empty())
    {
        int y=q.front();
        q.pop();
        v.push_back(y);
        for(auto it:adj[y])
        {
            indegree[it]--;
            if(indegree[it]==0)
            {
                q.push(it);
            }
        }

    }

}
int main()
{
    int V,E;
    cin>>V>>E;
    vector<vector<int>> adj(V,vector<int>());
    // vector<int> vis(V,0);
    vector<int> indegree(V,0);

    for(int i=0;i<E;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
      
    }   

    for(int i=0;i<V;i++)
    {
        for(auto it:adj[i])
        {
            indegree[it]++;
        }
    }

   
            topoBFS(adj,indegree);
        
    
    
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
}
// 6 6
// 5 0
// 4 0
// 5 2
// 2 3
// 3 1
// 4 1