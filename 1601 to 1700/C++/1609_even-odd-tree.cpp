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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            int prev, val;
            for(int i=0;i<size;i++){
                auto node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                if(i==0){
                    prev = node->val;
                    if((level%2==0 && prev%2==0) || (level%2==1 && prev%2==1)) return false;
                    continue;
                }
                val = node->val;
                if((level%2==0 && val%2==0) || (level%2==1 && val%2==1)) return false;
                if((level%2==0 && val<=prev) || (level%2==1 && val>=prev)) return false;
                prev = val;
            }
            level++;
        }
        return true;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}

