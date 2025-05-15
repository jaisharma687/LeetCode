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
    void postorder(TreeNode* root, vector<int>& output){
        if(root==nullptr) return;
        postorder(root->left,output);
        postorder(root->right,output);
        output.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(root,res);
        return res;
    }
};

class Solution {
    public:
        vector<int> postorderTraversal(TreeNode* root) {
            vector<int> postorder;
            if(root==NULL) return postorder;
            stack<TreeNode*> st1;
            stack<TreeNode*> st2;
            st1.push(root);
            while(!st1.empty()){
                auto node = st1.top();
                st1.pop();
                st2.push(node);
                if(node->left!=NULL) st1.push(node->left);
                if(node->right!=NULL) st1.push(node->right);
            }
            while(!st2.empty()){
                postorder.push_back(st2.top()->val);
                st2.pop();
            }
            return postorder;
        }
    };
    
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if(root==NULL) return postorder;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            auto node = st.top();
            st.pop();
            postorder.push_back(node->val);
            if(node->left!=NULL) st.push(node->left);
            if(node->right!=NULL) st.push(node->right);
        }
        reverse(postorder.begin(),postorder.end());
        return postorder;
    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if(root==NULL) return postorder;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        TreeNode* temp = NULL;
        while(curr!=NULL || !st.empty()){
            if(curr!=NULL){
                st.push(curr);
                curr = curr-> left;
            }else{
                temp = st.top()->right;
                if(temp!=NULL){
                    curr = temp;
                }else{
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->val);
                    while(!st.empty() && temp==st.top()->right){
                        temp = st.top();
                        st.pop();
                        postorder.push_back(temp->val);
                    }
                }
            }
        }
        return postorder;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}