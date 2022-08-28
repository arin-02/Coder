#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
   
   int t;
   cin>>t;
   while(t--){
    
        int n,x;
        cin>>n>>x;
        vector<int> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int len=0;
        int fixed=a[0];
        for(int i=1;i<n;i++)
        {
            // cout<<fixed<<"=fixed"<<endl;
            // cout<<a[i]-fixed<<endl;
            if((abs(a[i]-fixed))/2>(x))
            {
                fixed=a[i];
                
                    len++;
                
            }
        }
        
        cout<<len<<endl;
        

   }
       
}