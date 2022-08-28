#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node*links[26];
    bool flag=false;
    bool containsKey(char ch)
    {
        return (links[ch-'a']!=NULL);
    }
    void put (char ch,Node* node)
    {
        links[ch-'a'] = node;
    }
    Node *get(char ch)
    {
        return links[ch-'a'];

    }
    bool setEnd()
    {
        flag=true;
    }
    bool isEnd()
    {
        return flag;
    }
};
class Trie{
    private: 
            Node*root;

    public:
    // initialize
        Trie()
        {
            root=new Node();
        }
    // inserts a word into the trie
    // TC O(len)
    void insert(string word)
    {
        Node* node=root;
        for(int i=0; i<word.length(); i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i],new Node());
            }
            // moves to reference trie
            node=node->get(word[i]);
        }
        node->setEnd();
    }

    // returns if word is in the trie
    // TC O(len)
    bool search(string word)
    {
        Node* node=root;
        for(int i=0; i<word.length(); i++)
        {
            if(!node->containsKey(word[i]))
            {
                return false;
            }
            node=node->get(word[i]);
        }
        return node->isEnd();
    }

    // returns if any word is in the trie that starts with given string
    // TC O(len )
    bool startsWith(string prefix)
    {
        Node* node =root;
        for(int i=0; i<prefix.size(); i++)
        {
            if(!node->containsKey(prefix[i]))
            {
                return false;
            }
            node=node->get(prefix[i]);
        }
        return true;
    }
};
int main()
{
    int n = 5;
	vector<int>type = {1, 1, 2, 3, 2};
	vector<string>value = {"hello", "help", "help", "hel", "hel"};
	Trie trie;
    for (int i = 0; i < n; i++) {
		if (type[i] == 1) {
			trie.insert(value[i]);
		}
		else if (type[i] == 2) {
			if (trie.search(value[i])) {
				cout << "true" << "\n";
			}
			else {
				cout << "false" << "\n";
			}
		}
		else {
			if (trie.startsWith(value[i])) {
				cout << "true" << "\n";
			}
			else {
				cout << "false" << "\n";
			}
		}
	}
}