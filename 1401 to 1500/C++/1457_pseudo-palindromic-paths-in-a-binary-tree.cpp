#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// class Solution {
// public:
//     int dfs(TreeNode*root, vector<int>& freq){
//         if(root==nullptr){
//             return 0;
//         }
//         freq[root->val]++;
//         int res = 0;
//         if(root->left==nullptr && root->right==nullptr){
//             int odd = 0;
//             for(int x: freq){
//                 if(x%2==1){
//                     odd++;
//                 }
//             }
//             if(odd<2) res = 1;
//         }
//         int l = dfs(root->left, freq);
//         int r = dfs(root->right, freq);
//         freq[root->val]--;
//         return res + l + r;
//     }
//     int pseudoPalindromicPaths (TreeNode* root) {
//         vector<int> freq(10,0);
//         return dfs(root, freq);
//     }
// };

class Solution {
public:
    int dfs(TreeNode*root, int val){
        if(root==nullptr){
            return 0;
        }
        val = val ^ (1<<root->val);
        int res = 0;
        if(root->left==nullptr && root->right==nullptr){
            if((val & (val-1)) == 0) res = 1;
        }
        int l = dfs(root->left, val);
        int r = dfs(root->right, val);
        return res + l + r;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        return dfs(root, 0);
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}

