#include<iostream>
#include<vector>
#include<string>
using namespace std;


int main()
{
    string s="abc";
    int n=s.length();
    for(int i=0; i<(1<<n)-1;i++)
    {
        string str="";
        for(int j=0; j<n; j++)
        {
            if(i&(1<<j)) //telling the bit is set or not
            {
                str+=s[j];
            }
        }
        cout<<str<<endl;
    }
   
}