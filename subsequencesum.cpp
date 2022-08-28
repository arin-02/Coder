#include<iostream>
#include <vector>
using namespace std;


void print( vector<int> r)
{
    for( int i = 0; i < r.size(); i++ )
    {
        cout<< r[i] <<" ";
    }
}
/* 
    3 1 2
    to 3 1
    3 2 
    lekin 2 1 is order mei nhi rah skta .. order same hona chahiye baki kaise likho 
*/

void subsequencesum(vector<int> v,vector<int> &r,int index,int k,int sum,int n)
{
    
    if(sum==k)
    {
        print(r);
        cout<<endl;
        return;
    }
    
    
    r.push_back(v[index]);
    sum+=v[index];
    subsequencesum(v,r,index+1,k,sum,n); 
    sum-=v[index];
    r.pop_back();
    subsequencesum(v,r,index+1,k,sum,n);  
}
int main()
{
    vector<int> arr(3);
    int k=2,sum=0;
    for(int i=0;i<3;i++)
    {
        // 3,1,2
        cin>>arr[i];
    }
    vector<int> r;
    subsequencesum(arr,r,0,k,0,3);

}