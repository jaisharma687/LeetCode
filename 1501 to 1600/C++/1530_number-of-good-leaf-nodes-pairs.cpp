#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> findDistance(TreeNode* root,int dist,int& pairs){
        if(root == nullptr) return {};
        if(root->left == nullptr && root->right == nullptr) return {1};

        vector<int> left_dist = findDistance(root->left,dist,pairs);
        vector<int> right_dist = findDistance(root->right,dist,pairs);

        for(auto x: left_dist){
            for(auto y: right_dist){
                if(x+y<=dist) pairs++;
            }
        }

        vector<int> all_dist;
        for(auto x: left_dist){
            if(x+1<dist) all_dist.push_back(x+1);
        }
        for(auto x:right_dist){
            if(x+1<dist) all_dist.push_back(x+1);
        }
        return all_dist;
    }
    int countPairs(TreeNode* root, int distance) {
        int pairs = 0;
        findDistance(root,distance,pairs);
        return pairs;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}