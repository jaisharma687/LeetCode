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

class Solution {
public:
    vector<vector<int>> out;
    void dfs(TreeNode* root, int currSum, int targetSum, vector<int>& path){
        if(root->left==nullptr && root->right==nullptr){
            if(currSum == targetSum){
                out.push_back(path);
            }
            return;
        }
        if(root->left!=nullptr){
            path.push_back(root->left->val);
            dfs(root->left, currSum + root->left->val, targetSum, path);
            path.pop_back();
        }
        if(root->right!=nullptr){
            path.push_back(root->right->val);
            dfs(root->right, currSum + root->right->val, targetSum, path);
            path.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==nullptr){
            return {};
        }
        vector<int> path = {root->val};
        dfs(root, root->val, targetSum, path);
        return out;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}

