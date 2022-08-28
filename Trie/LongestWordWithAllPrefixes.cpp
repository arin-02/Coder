#include<bits/stdc++.h>
using namespace std;

struct Node{

    Node* links[26];
    bool flag=false;

    bool containskey(char ch)
    {
        return links[ch-'a']!=NULL;
    }
    
    void put(char ch,Node* node)
    {
        links[ch-'a']=node;
    }
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
    void setEnd()
    {
        flag=true;
    }
    bool isEnd()
    {
        return flag;
    }
};
class Trie
{
    private:
        Node*root;
    public:
            Trie()
            {
                root=new Node();
            }
            void insert(string word)
            {
                Node* node=root;
                for(int i=0;i<word.length();i++)
                {
                    if(!node->containskey(word[i]))
                    {
                        node->put(word[i],new Node());
                    }
                        node=node->get(word[i]);
                }
                node->setEnd();
            }
            
            
            bool checkifprefixexists(string word)
            {
                bool fl=true;
                Node* node=root;
                for(int i=0;i<word.length();i++)
                {
                    if(node->containskey(word[i]))
                    {
                        node=node->get(word[i]);//phele reference pe gye vha flag ki value chekc kro
                        fl=fl && node->isEnd();
                    } 
                    else
                    {
                    return false;

                    }
                }
                return fl;
            }
    
};
int main()
{
       vector<string> arr={"n","ni","nin","ninj","ninja","ninga"};
       int n=6;
       Trie trie;
       for(int i=0;i<n;i++)
       {
        trie.insert(arr[i]);
       }

        string longest="";
        for(auto &it:arr)
        {
            if(trie.checkifprefixexists(it))
            {
                if(it.length()> longest.length())
                {
                    longest=it;
                }
                else if(it.length()== longest.length() && it<longest)
                {
                    longest=it;
                }
            }
        }
        if(longest=="")cout<< "NONE";
        cout<<longest<<endl;
       
}