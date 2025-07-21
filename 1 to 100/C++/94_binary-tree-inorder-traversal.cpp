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
    void inorder(TreeNode* root, vector<int>& output){
        if(root == nullptr) return;
        inorder(root->left,output);
        output.push_back(root->val);
        inorder(root->right,output);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root,res);
        return res;
    }
};

class Solution {
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> inorder;
            if(root==NULL) return inorder;
            stack<TreeNode*> st;
            TreeNode* node = root;
            while(true){
                if(node!=NULL){
                    st.push(node);
                    node = node->left;
                }else{
                    if(st.empty()) break;
                    node = st.top();
                    st.pop();
                    inorder.push_back(node->val);
                    node = node->right;
                }
            }
            return inorder;
        }
    };

// Morris Traversal
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* curr = root;
        while(curr!=nullptr){
            if(curr->left==nullptr){
                res.push_back(curr->val);
                curr = curr->right;
            }else{
                TreeNode* lc = curr->left;
                while(lc->right!=nullptr) lc = lc->right;
                lc->right = curr;
                TreeNode* temp = curr->left;
                curr->left = nullptr;
                curr = temp;
            }
        }
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}