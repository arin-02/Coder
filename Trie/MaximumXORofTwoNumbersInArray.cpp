#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[2]; // 0 ya 1 se ke hee link hoga
    bool containskey(int bit)
    {
        return links[bit]!=NULL;
    }
    Node* get(int bit)
    {
        return links[bit];
    }
    void put(int bit,Node* node)
    {
        links[bit] = node;
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
    void insert(int num)
    {
        Node* node = root;
        for(int i=31;i>=0;i--)
        {
            int bitt=((num>>i)&1);//bit is set or not
            if(!node->containskey(bitt))
            {
                node->put(bitt,new Node());
            }
            node=node->get(bitt);
        }
    }

      int getMax(int num)
      {
        Node* node =root;
        int maxNum=0;
        for(int i=31;i>=0;i--)
        {
            int bitt=((num>>i)&1); //bit is set or not
            if(node->containskey(1-bitt))
            {
                maxNum=maxNum|(1<<i);
                node=node->get(1-bitt);
            }
            else
            {
                node=node->get(bitt);
            }
        }
        return maxNum;
      }  
};
int main()
{
    vector<int> arr1={6,8};
    int n=arr1.size();
    int maxi=0;
    vector<int> arr2={7,8,2};
    int m=arr2.size();
    Trie trie;   
    for(auto &it: arr1)
    {
        trie.insert(it);
    }

    for(auto &it:arr2)
    {
        maxi=max(maxi,trie.getMax(it));
    }
    cout<<maxi<<endl;

}