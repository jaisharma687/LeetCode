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

// BFS
class Solution {
    public:
        bool isCompleteTree(TreeNode* root) {
            if(root==nullptr) return true;
            queue<TreeNode*> q;
            q.push(root);
            bool past = false;
            while(!q.empty()){
                auto node = q.front();
                q.pop();
                if(node==nullptr) past = true;
                else{
                    if(past) return false;
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            return true;
        }
    };

// DFS
class Solution {
public:
    int countNodes(TreeNode* root){
        if(root==nullptr) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    bool dfs(TreeNode* root, int i, int total){
        if(root==nullptr) return true;
        if(i>total) return false;
        return dfs(root->left,2*i,total) && dfs(root->right,2*i+1,total);
    }
    bool isCompleteTree(TreeNode* root) {
        int total = countNodes(root);
        return dfs(root,1,total);
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}

