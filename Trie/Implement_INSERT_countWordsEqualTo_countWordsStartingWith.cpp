#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node*links[26];
    
    int countendwith=0;
    int countprefix=0;

    bool containskey(char ch)
    {
        return (links[ch-'a']!=NULL);
    }
    Node*get(char ch)
    {
        return links[ch-'a'];
    }
    void put(char ch,Node *node)
    {
        links[ch-'a'] = node;
    }
    void increasedend()
    {
        countendwith++;
    }
    void increaseprefix()
    {
        countprefix++;
    }
    void deleteend()
    {
        countendwith--;
    }
    void reduceprefix()
    {
        countprefix--;
    }
    int getend()
    {
        return countendwith;
    }
    int getprefix()
    {
        return countprefix;
    }
};
class Trie{

    private:
        Node* root;
    public: 
        Trie()
        {
            root = new Node();
        }
        void insert(string word)
        {
            Node* node=root;
            for(int i=0; i<word.length(); i++)
            {
                if(!node->containskey(word[i]))
                {
                    node->put(word[i],new Node());//nya node bnayay uske andr link vlue dala
                }
                node=node->get(word[i]);//new node bnaya uspe gye
                    node->increaseprefix();
            }
            node->increasedend();
        }
        int countwordsequalto(string &word)
        {
            Node*node=root;
            for(int i=0;i<word.length();i++)
            {
                if(node->containskey(word[i]))//agle pe contain hogi
                {
                    //agle pe chalo fir
                    node=node->get(word[i]);
                 
                }
                else{
                    return 0;
                }
            }
            node->getend();
        }
        int countWordsStartingWith( string &word)
        {
            Node*node=root;
            for(int i=0;i<word.length();i++)
            {
                if(!node->containskey(word[i]))
                {
                    return 0;
                }
                else
                {
                    node=node->get(word[i]);
                }
            }
            return node->getprefix();
        }

        void erase(string &word)
        {
            Node*node=root;
            for(int i=0;i<word.length();i++)
            {
                if(node->containskey(word[i]))
                {
                    node=node->get(word[i]);
                    node->reduceprefix();
                }
                else
                {
                    return;
                }
            }
            node->deleteend();
        }
};
int main()
{
    Trie T;
  T.insert("apple");
  T.insert("apple");
  T.insert("apps");
  T.insert("apps");

   string word1 = "apps";
  cout<<"Count Words Equal to "<< word1<<" "<<T.countwordsequalto(word1)<<endl;
   
  string word2 = "abc";
  cout<<"Count Words Equal to "<< word2<<" "<<T.countwordsequalto(word2)<<endl;
  string word3 = "ap";
  cout<<"Count Words Starting With "<<word3<<" "<<T.countWordsStartingWith(word3)
  <<endl;
  string word4 = "appl";
  cout<<"Count Words Starting With "<< word4<<" "<<T.countWordsStartingWith(word4)
  <<endl;
  T.erase(word1);
  cout<<"Count Words equal to "<< word1<<" "<<T.countwordsequalto(word1)<<endl;
  return 0;
}