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
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int k = 0;
        ListNode* temp = head;
        vector<vector<int>> res(m,vector<int>(n,-1));
        int r_min = 0;int c_min = 0;int r_max = m-1;int c_max = n-1;
        while(temp!=nullptr){
            for(int j=c_min;j<=c_max && temp!=nullptr;j++){
                res[r_min][j] = temp->val;
                temp = temp->next;
            }
            r_min++;
            for(int i=r_min;i<=r_max && temp!=nullptr;i++){
                res[i][c_max] = temp->val;
                temp = temp->next;
            }
            c_max--;
            for(int j=c_max;j>=c_min && temp!=nullptr;j--){
                res[r_max][j] = temp->val;
                temp = temp->next;
            }
            r_max--;
            for(int i=r_max;i>=r_min && temp!=nullptr;i--){
                res[i][c_min] = temp->val;
                temp = temp->next;
            }
            c_min++;
        }
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}