#include<bits/stdc++.h>
using namespace std;
//  O(n^2)
struct Node{
    Node* links[26];
    bool flag=false;
    bool containskey(char ch)
    {
        return (links[ch-'a']!=NULL) ;
    }
    void put(char ch,Node* node)
    {
        links[ch-'a'] = node;
    }
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
};
class Trie
{
    private:
        Node* root;
    public:
        Trie()
        {
            root=new Node();
        }
        int countDistinctSubstrings(string &s)
        {
            int count=0;
          
            for(int i=0;i<s.length();i++)
            {
                Node*node=root;
                for(int j=i;j<s.length();j++)
                {
                    if(!node->containskey(s[j]))
                    {
                        count++;
                        node->put(s[j],new Node());
                    }
                node=node->get(s[j]);
                }
            }
            return count+1; //empty string bhi leni hai isliye +1 kia

        }
        

};


int main()
{
    Trie t;
    string s="abab";
    cout<<t.countDistinctSubstrings(s);
}