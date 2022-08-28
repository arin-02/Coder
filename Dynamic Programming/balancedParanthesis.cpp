#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isopening(char curr)
{
    if(curr == '('||curr == '{' || curr == '[')
    return true;

    return false;
}
bool ismatching(char curr,char b)
{
    if(b=='('&& curr==')')return true;
    else if(b=='{'&& curr=='}')return true;
    else if(b=='['&& curr==']')return true;
    return false;
}
bool paranthesis(string str)
{
    stack<char> st;
    for(int i=0; i<str.length(); i++)
    {
        char curr=str[i];
        if(isopening(curr))
        {
            st.push(curr);
            
        }
        else
        {
            if(st.empty())return false;

            else if(!ismatching(curr,st.top()))
            {
                return false;
            }
            else{
                st.pop();
            }
        }
    }
    if(st.empty())return true;
    return false;

}
int main()
{
    string str="(({[]}))";
    cout<<paranthesis(str);
}