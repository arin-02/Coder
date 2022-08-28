#include<iostream>
#include <vector>
using namespace std;

void print(vector<int> r)
{
    for(int i=0; i<r.size(); i++)
    {
        cout<<r[i]<<" ";
    }

}
/* 
    3 1 2
    to 3 1
    3 2 
    lekin 2 1 is order mei nhi rah skta .. order same hona chahiye baki kaise likho 
*/
void subsequence(vector<int> v,vector<int> r,int index) 
    {
        int n=v.size();
        if(index>=n)
        {
            print(r);
            cout<<endl;
        if(r.size()==0)
        {
            cout<<"{}"<<endl;
        }
            return;
        }

        r.push_back(v[index]);
        subsequence(v,r,index+1);
        r.pop_back();
        subsequence(v,r,index+1);

    }
int main()
{
    vector<int> arr(3);
    for(int i=0;i<3;i++)
    {
        // 3,1,2
        cin>>arr[i];
    }
    vector<int> r;
    subsequence(arr,r,0);

}