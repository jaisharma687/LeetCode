#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        int md = 0;
        int maxDepth(TreeNode* root){
            if(root==nullptr){
                return 0;
            }
            int cd = 1 + max(maxDepth(root->left),maxDepth(root->right));
            md = max(md, cd);
            return cd; 
        }
        TreeNode* lca(TreeNode* root, int cd){
            if(root==nullptr || cd==md-1){
                return root;
            }
            TreeNode* left = lca(root->left, cd+1);
            TreeNode* right = lca(root->right, cd+1);
            if(left==nullptr && right==nullptr) return nullptr;
            if(left!=nullptr && right!=nullptr) return root;
            return left==nullptr?right:left;
        }
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            maxDepth(root);
            return lca(root, 0);
        }
    };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();