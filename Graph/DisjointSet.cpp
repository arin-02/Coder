// vo element kis component mei hai ismei help krta
#include<bits/stdc++.h>
using namespace std;
int parent[10000];
int ranki[10000];
int n=5;
void makeset()
{
    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
        ranki[i]=0;
    }
}

int findparent(int node)
{
    if(node==parent[node])
    {
        return node;
    }
    return parent[node]=findparent(parent[node]);
}

void unioning(int u,int v)
{
    u=findparent(u);
     v=findparent(v);
     if(ranki[u]<ranki[v])
     {
        parent[u]=v;

     }
     else if(ranki[u]>ranki[v])
    {
        parent[v]=u;
    }
    else{
        parent[v]=u;
        ranki[u]++;
    }
}
int main()
{
    makeset();   
    int m;
    cin>>m;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        unioning(u,v);
        // 
    }
    if(findparent(2)!=findparent(4))
    {
        cout<<"different components"<<endl;
    }
    // if(findparent(2)!=findparent(3))
    // {
    //     cout<<"different components"<<endl;
    // }
    else
    {
        cout<<"same components"<<endl;
    }
}