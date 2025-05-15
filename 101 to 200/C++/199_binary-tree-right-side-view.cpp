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
        vector<int> rightSideView(TreeNode* root) {
            vector<int> res;
            if(root==NULL) return res;
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()){
                int size = q.size();
                while(size--){
                    auto node = q.front();
                    q.pop();
                    if(node->left!=NULL) q.push(node->left);
                    if(node->right!=NULL) q.push(node->right);
                    if(size==0) res.push_back(node->val);
                }
            }
            return res;
        }
    };


class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return {};
        vector<int> res;
        stack<pair<TreeNode*,int>> st;
        st.push({root,0});
        while(!st.empty()){
            auto [node,level] = st.top();
            st.pop();
            if(node->right!=NULL) st.push({node->right,level+1});
            if(node->left!=NULL) st.push({node->left,level+1});
            if(res.size()>=level+1){
                res[level] = node->val;
            }else{
                res.push_back(node->val);
            }
        }
        return res;
    }
};

class Solution {
    public:
        vector<int> rightSideView(TreeNode* root) {
            if(root==NULL) return {};
            vector<int> res;
            stack<pair<TreeNode*,int>> st;
            st.push({root,0});
            while(!st.empty()){
                auto [node,level] = st.top();
                st.pop();
                if(node->right!=NULL) st.push({node->right,level+1});
                if(node->left!=NULL) st.push({node->left,level+1});
                if(res.size()>=level+1){
                    res[level] = node->val;
                }else{
                    res.push_back(node->val);
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

