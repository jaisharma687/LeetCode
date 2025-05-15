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
    void preorder(TreeNode* root, vector<int>& output){
        if(root==nullptr) return;
        output.push_back(root->val);
        preorder(root->left,output);
        preorder(root->right,output);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root,res);
        return res;
    }
};

class Solution {
    public:
        vector<int> preorderTraversal(TreeNode* root) {
            vector<int> preorder;
            stack<TreeNode*> st;
            if(root==NULL) return preorder;
            st.push(root);
            while(!st.empty()){
                auto node = st.top();
                st.pop();
                if(node->right!=NULL) st.push(node->right);
                if(node->left!=NULL) st.push(node->left);
                preorder.push_back(node->val);
            }
            return preorder;
        }
    };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}