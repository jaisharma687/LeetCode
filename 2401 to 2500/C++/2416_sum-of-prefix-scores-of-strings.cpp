#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

struct TrieNode{
    int countOcc;
    TrieNode* children[26];
};

class Solution {
public:
    TrieNode* createTrie(){
        TrieNode* t = new TrieNode();
        for(int i=0;i<26;i++){ 
            t->children[i]=nullptr;
        }
        t->countOcc = 0;
        return t;
    }

    void insertTrie(string s, TrieNode* root){
        TrieNode* trav = root;
        for(char ch: s){
            int idx = ch-'a';
            if(trav->children[idx]==nullptr){
                trav->children[idx] = createTrie();
            }
            trav = trav->children[idx];
            trav->countOcc++;
        }
    }

    int searchTrie(string s, TrieNode* root){
        TrieNode* trav = root;
        int len = 0;
        for(char ch: s){
            int idx = ch-'a';
            if(trav->children[idx]){
                trav = trav->children[idx];
                len += trav->countOcc;
            }
            else break;
        }
        return len;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> res;
        TrieNode* root = createTrie();
        for(string word: words) insertTrie(word,root);
        for(string word: words) res.push_back(searchTrie(word,root));
        return res;
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();