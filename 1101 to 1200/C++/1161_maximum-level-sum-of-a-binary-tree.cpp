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
    int maxLevelSum(TreeNode* root) {
        int level=1;
        int maxSum = INT_MIN;
        int minLevel;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int sum = 0;
            for(int i=0;i<size;i++){
                auto node = q.front();
                q.pop();
                if(node->left!=nullptr) q.push(node->left);
                if(node->right!=nullptr) q.push(node->right);
                sum += node->val;
            }
            if(sum>maxSum){
                maxSum = sum;
                minLevel = level;
            }
            level++;
        }
        return minLevel;
    }
};

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        stack<pair<TreeNode*,int>> st;
        st.push({root,1});
        map<int,int> levelSum;
        while(!st.empty()){
            auto [node, level] = st.top();
            st.pop();
            levelSum[level] += node->val;
            int sum = levelSum[level];
            if(node->left!=nullptr) st.push({node->left,level+1});
            if(node->right!=nullptr) st.push({node->right,level+1});
        }
        int minLevel;
        int maxSum = INT_MIN;
        for(auto& [level, sum]: levelSum){
            if(sum>maxSum){
                minLevel = level;
                maxSum = sum;
            }
        }
        return minLevel;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}

