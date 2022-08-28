#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// pichle mei vector le rhe the ismei nhi lenge
// SC bchaya 
void permutation(vector<int> &nums,vector<vector<int> >&v,int index)
{
    if(nums.size()==index)
    {
        v.push_back(nums);
        return;
    }
    for(int i=index;i<nums.size();i++)
    {
        swap(nums[index],nums[i]);
        permutation(nums,v,index+1);
        swap(nums[index],nums[i]);   
    }
}
int main()
{
    vector<vector<int> >v;
    vector<int> nums={1,2,3};
   int index=0;
    // n!*n TC
    // SC 
    permutation(nums,v,index);
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

}