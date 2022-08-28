#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
// void print(unordered_map<char,int> um)
// {
//     for(auto &it:um)
//     {
//         cout<<it.first<<" "<<it.second;   
//     }
// }
int main()
{
    // find max aur minimum sum of subarray of size k
    string s="aabaabaa";
    int n=s.length();
    string k="aaba";
    
    int i=0;
    int j=0;
    unordered_map<char,int> um;
    
    for(int i=0; i<k.length(); i++)
    {
        um[k[i]]++;
    }
    int count=um.size();
    int ans=0;
    vector<int> v;
    while(j<n)
    {
        // calculation part
       
            if (um.find(s[j]) != um.end())
            {
            um[s[j]]--;
            // print(um);
            // cout<<endl;

            }
            if(um[s[j]]==0)count--;
            // cout<<count<<" ## "<<endl;
        // window length not achieved
        if(j-i+1<k.length())
        {
            j++;

        }
        // window length achieved
        else if(j-i+1==k.length()) {
      
            if(count==0)
            {
                ans++;
            }
            if (um.find(s[i]) != um.end())
            {
            um[s[i]]++;
            // cout<<endl;
            // print(um);
            // cout<<"##"<<endl;

            }
            if(um[s[i]]==1)
            {
                count++;
            }
            // cout<<count<<endl<<endl;
    //    slide the window
            
            i++;
            j++;
           
        }
            

        

    }
    cout<<ans<<endl;

}