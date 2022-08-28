// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     // your code goes here
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         int n;
//         cin>>n;
//           int a[n];
//           for(int i=0;i<n;i++)
//           {
//               cin>>a[i];
//           }
//         stack<int>st;
//         int p =0;
//         int count =0;
//         for(int i=0;i<n;i++)
//         {
//             if(a[i]==1)
//             {
//                 p++;
//                 st.push(1);
//             }
//             else
//             {
//                 while(!st.empty())
//                 {
//                     st.pop();
//                    count++;
//                 }
//                 if(count!=1)
//                 p++;
//                 count =0;
//             }
//         }
//          while(!st.empty())
//                 {
//                     st.pop();
//                    count++;
//                 }
//                 if(count!=1)
//                 p++;
//         cout<<p<<endl;

//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int main() {
    // your code goes here
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
          int a[n];
          for(int i=0;i<n;i++)
          {
              cin>>a[i];
          }
        stack<int> st;
        int p=0;
        int last=0;
        int sz,tt;
        for(int i=0;i<n;i++)
        {
            if(a[i]==1)
            {
                p++;
                st.push(1);
                last=st.size();
            }
            else
            {
                 sz=st.size();
                 tt=(sz*(sz-1))/2;
                p+=tt;
                while(st.size()!=0)
                {
                    st.pop();
                }
            }
            
        }
         sz=st.size();
             tt=(sz*(sz-1))/2;
                p+=tt;
        cout<<p<<endl;


    }
    return 0;
}