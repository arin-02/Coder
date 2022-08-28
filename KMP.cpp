#include<bits/stdc++.h>
using namespace std;

void KMP(string s,int n,vector<int> &lps)/*Longest Proper Prefix whix is also suffix*/
{
    
    // lps[0]=0;
    for(int j=1;j<n;j++)
    {
        int i=lps[j-1];
        
        while(i>0 && s[j]!=s[i])
        {
            i=lps[i-1];
        
        }
        if(s[i]==s[j])
        {
            i++;
        }
        lps[j]=i;

    }
    for(int z=0;z<lps.size();z++)
    {
        cout<<lps[z]<<" ";
    }
}
int main()
{
       string s="apnacollege";
       string t="na";
       int n=s.length();
       vector<int> lps(n,0);
       
       KMP(s,n,lps);
       int pos=-1;
       int i=0,j=0;
       while(i<s.size())
       {
        if(s[i]==t[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j!=0) j=lps[j-1];
            else i++;
        }
        if(j==t.size())
        {
            pos=i-t.size();
            break;
        }
       }    
cout<<endl;
cout<<"index of that t string = "<<endl;
    cout<<pos<<endl;
}