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
    TreeNode* del(TreeNode*& root, unordered_set<int> to_del, vector<TreeNode*>& out) {
        if (root == NULL) return nullptr;
        root->left =  del(root->left, to_del, out);
        root->right = del(root->right, to_del, out);
        if (to_del.count(root->val)) {
            if (root->left != NULL) out.push_back(root->left);
            if (root->right != NULL) out.push_back(root->right);
            delete root;
            return nullptr;
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> output;
        unordered_set<int> to_del(to_delete.begin(),to_delete.end());
        if(del(root,to_del,output)) output.push_back(root);
        return output;
    }
};

// Optimal
class Solution {
    public:
        vector<TreeNode*> res;
        TreeNode* dfs(TreeNode* root, unordered_set<int>& to_del){
            if(root==nullptr) return nullptr;
            root->left = dfs(root->left, to_del);
            root->right = dfs(root->right, to_del);
            if(to_del.find(root->val)!=to_del.end()){
                if(root->left!=nullptr) res.push_back(root->left);
                if(root->right!=nullptr) res.push_back(root->right);
                return nullptr;
            }
            return root;
        }
        vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
            unordered_set<int> to_del(to_delete.begin(),to_delete.end());
            dfs(root,to_del);
            if(to_del.find(root->val)==to_del.end()){
                res.push_back(root);
            }
            return res;
        }
    };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}