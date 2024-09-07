#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool traverse(ListNode* head, TreeNode* root){
        if(head == nullptr) return true;
        if(root == nullptr) return false;
        if(root->val == head->val){
            if(traverse(head->next,root->left)) return true;
            if(traverse(head->next,root->right)) return true;
        }
        return false;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root == nullptr) return false;
        if(traverse(head,root)) return true;
        if(isSubPath(head,root->left)) return true;
        if(isSubPath(head,root->right)) return true;
        return false;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}