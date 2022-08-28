// if n=10^5 ...then o(n^2) tle dega ,,, kyuki 10^7 se k to isliye binary search
#include<bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> arr={1,7,8,4,5,6,-1,9};
    int n=arr.size(); 
    vector<int> temp;
    int len=1;
    temp.push_back(arr[0]);
    for(int i=1; i<n; i++)
    {
        if(arr[i]>temp.back())
        {
            temp.push_back(arr[i]);
            len++;
        }
        else
        {
            int ind=lower_bound(temp.begin(), temp.end(), arr[i])-temp;
            temp[ind]=arr[i];
        }
    }   
    cout<<len<<endl;
}