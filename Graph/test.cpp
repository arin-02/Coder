#include<bits/stdc++.h>
using namespace std;


bool solve(string a,string b,int n,int m,int r)
{
   int i=n-1;
   int j=m-1;
   
   

        bool f=false;
        while(j>=1)
        {
            if(a[i]!=b[j])
            {
                return f;
            }
            i--;
            j--;
        }
        
        if(b[j]=='1')
        {
            while(i>=0)
            {
                if(a[i]=='1')
                {
                f=true;

                }
                    i--;
            }
        }
        else 
        {
             while(i>=0)
            {
                if(a[i]=='0')
                {
                f=true;

                }
                    i--;
            }
        }
    return f;
        
        
   
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        string a;
        cin>>a;
        string b;
        cin>>b;
        int r=n-m;
        if(solve(a,b,n,m,r))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        

    }
}