#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

// HashSet method

// class Solution {
// public:
//     int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
//         unordered_set<int> s;
//         for(int x: arr1){
//             while(x>0){
//                 if(!s.contains(x)){
//                     s.insert(x);
//                 }
//                 x/=10;
//             }
//         }
//         int res = 0;
//         for(int x: arr2){
//             while(x>0){
//                 if(s.contains(x)){
//                     res = max((int)log10(x)+1,res);
//                     break;
//                 }
//                 x/=10;
//             }
//         }
//         return res;
//     }
// };


// Trie Method

struct TrieNode{
    TrieNode* children[10]; //0,1,2,3,...9
};

class Solution {
public:
    TrieNode* createNode(){
        TrieNode* t = new TrieNode();
        for(int i=0;i<10;i++) t->children[i] = nullptr;
        return t;
    }

    void insertNode(int num, TrieNode * root){
        string numStr = to_string(num);
        TrieNode* trav = root;
        for(char ch: numStr){
            int idx = ch-'0';
            if(trav->children[idx]==nullptr){
                trav->children[idx] = createNode();
            }
            trav = trav->children[idx];
        }
    }

    int searchTrie(int num, TrieNode * root){
        string numStr = to_string(num);
        TrieNode* trav = root;
        int len = 0;
        for(char ch: numStr){
            int idx = ch-'0';
            if(trav->children[idx]){
                len++;
                trav = trav->children[idx];
            }
            else break;
        }
        return len;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode * root = createNode();
        for(int x: arr1) insertNode(x,root);
        int res = 0;
        for(int x: arr2) res = max(res,searchTrie(x,root));
        return res;
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();