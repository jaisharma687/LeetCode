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
    unordered_map<TreeNode* ,TreeNode*> parentChild;
    void inorder(TreeNode* root){
        if(root==nullptr) return;
        if(root->left!=nullptr){
            parentChild[root->left] = root;
        }
        inorder(root->left);
        if(root->right!=nullptr){
            parentChild[root->right] = root;
        }
        inorder(root->right);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        parentChild.clear();
        inorder(root);
        queue<TreeNode*> q;
        q.push(target);
        unordered_set<int> visited;
        while(!q.empty()){
            int size = q.size();
            if(k==0) break;
            for(int i=0;i<size;i++){
                auto node = q.front();
                q.pop();
                visited.insert(node->val);
                if(node->left && visited.find(node->left->val)==visited.end()){ 
                    q.push(node->left);
                }
                if(node->right && visited.find(node->right->val)==visited.end()){ 
                    q.push(node->right);
                }
                if(parentChild.find(node)!=parentChild.end() && visited.find(parentChild[node]->val)==visited.end()){ 
                    q.push(parentChild[node]);  
                }
            }
            k--;
        }
        vector<int> res;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            res.push_back(node->val);
        }
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}

