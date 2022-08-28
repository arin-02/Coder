#include<bits/stdc++.h>
#include<numeric>
using namespace std;
 int gcd(int a,int b)
 {
    if(b==0)  return a;
    return gcd(b,a%b);
 }
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int  n,m;
        cin>>n>>m;
        int i=n;
        int j=m;
        int maxi=0;
        cout<<gcd(5,6);
        int a,b;
        while(i<=m &&j>=n)
        {
            if( gcd(i,j)>=n && j-i>=maxi)
            {
                maxi=max(maxi,j-i);
                a=i;
                b=j;
                
            }
            else
            {
                i++;
                j--;
            }
        }
        cout<<a<<" "<<b<<endl;

    }
}