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
//     TreeNode* replaceValueInTree(TreeNode* root) {
//         unordered_map<int,int> levelSum;
//         queue<pair<TreeNode*,int>> q;
//         q.push({root,0});
//         while(!q.empty()){
//             auto [node, level] = q.front();
//             q.pop();
//             levelSum[level] += node->val;
//             if(node->left) q.push({node->left, level+1});
//             if(node->right) q.push({node->right, level+1});
//         }
//         q.push({root,0});
//         root->val = 0;
//         while(!q.empty()){
//             auto [node, level] = q.front();
//             q.pop();
//             int siblingSum = 0;
//             if(node->left) siblingSum += node->left->val;
//             if(node->right) siblingSum += node->right->val;
//             if(node->left){
//                 node->left->val = levelSum[level+1] - siblingSum;
//                 q.push({node->left, level+1});
//             }
//             if(node->right){
//                 node->right->val = levelSum[level+1] - siblingSum;
//                 q.push({node->right, level+1});
//             }
//         }
//         return root;
//     }
// };

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int levelSum = root->val;
        while(!q.empty()){
            int size = q.size();
            int nextLevelSum = 0;
            while(size--){
                auto node = q.front();
                q.pop();
                node->val = levelSum - node->val;
                int siblingSum = 0;
                if(node->left){
                    nextLevelSum += node->left->val;
                    siblingSum += node->left->val;
                }
                if(node->right){
                    nextLevelSum += node->right->val;
                    siblingSum += node->right->val;
                }
                if(node->left){
                    node->left->val = siblingSum;
                    q.push(node->left);
                }
                if(node->right){
                    node->right->val = siblingSum;
                    q.push(node->right);
                }
            }
            levelSum = nextLevelSum;
        }
        return root;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}

