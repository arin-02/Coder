#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void permutation(vector<int> nums,vector<vector<int> >&v,vector<int>v1,int visited[])
{
    if(nums.size()==v1.size())
    {
        v.push_back(v1);
        return;
    }
    for(int i=0;i<nums.size();i++)
    {
        if(!visited[i])
        {
            v1.push_back(nums[i]);
            visited[i] =1;
            permutation(nums,v,v1,visited);
            visited[i] = 0;
            v1.pop_back();
        }
    }
}
int main()
{
    vector<vector<int> >v;

    vector<int> v1;
    vector<int> nums={1,1,0,1};
    int visited[24]={0};
    // n!*n TC
    // SC O(n) + O(n)
    permutation(nums,v,v1,visited);
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

}