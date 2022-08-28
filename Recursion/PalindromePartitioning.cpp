#include<bits/stdc++.h>
using namespace std;

bool ispalindrome(string s,int start,int end)
{
    while(start<=end)
    {
        if(s[start] != s[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}
void solve(vector<vector<string>> &ans,string &s,vector<string> &tempstr,int index)
{
    if(index==s.length())
    {
        ans.push_back(tempstr);
        return;
    }
    for(int i=index;i<s.length();i++)
    {
        if(ispalindrome(s,index,i))
        {
            tempstr.push_back(s.substr(index,i-index+1));
            solve(ans,s,tempstr,i+1);
            tempstr.pop_back();
        }
    }

}
int main()
{
    string s="aabb";
    int n=s.length();
    vector<string> tempstr;
    vector<vector<string>> ans;
    // vector<string> v;
    solve(ans,s,tempstr,0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {

        cout<<ans[i][j]<<endl;
        }
    }

}