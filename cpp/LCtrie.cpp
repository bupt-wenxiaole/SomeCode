#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode; //初始化根节点    
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur = root; //当前的节点是根节点
        for(int i = 0; i < word.length(); ++i)
        {
            int k = (word[i] - 'a');
            if(cur -> next[k] == NULL)
            {
                cur -> next[k] = new TrieNode();
            }
            cur = cur -> next[k];
        }
        cur -> exsit = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* cur = root;
        for(int i = 0; i < word.length(); ++i)
        {
            int k = word[i] - 'a';
            if(cur -> next[k] == NULL)
                return false;
            cur = cur -> next[k];
        }
        if(cur -> exsit)
            return true;
        else 
            return false;
        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(int i = 0; i < prefix.length(); ++i)
        {
            int k = prefix[i] - 'a';
            if(cur -> next[k] == NULL)
                return false;
            cur = cur -> next[k];
        }
        return true;
    }
    struct TrieNode
    {
        TrieNode* next[26];
        bool exsit;
        TrieNode() : exsit(false)
        {
            memset(next, 0, sizeof(next));
        }
    };
    TrieNode* root;
    
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

int main(int argc, char const *argv[])
{
    Trie* obj = new Trie();
    string word1 = "abb";
    obj -> insert(word1);
    string word2 = "abc";
    obj -> insert(word2);
    bool param_1 = obj -> search("abc");
    string word3 = "abc";
    bool param_2 = obj -> startsWith(word3);
    cout << param_2 << endl;
    return 0;
 }
