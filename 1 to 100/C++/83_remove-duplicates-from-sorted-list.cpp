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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        ListNode* node = NULL;
        ListNode* del = NULL;
        while(temp!=NULL){
            node = temp;
            temp = temp->next;
            if(temp != NULL && temp->val == node->val){
                node->next = temp->next;
                temp->next = NULL;
                del = temp;
                temp = node;
                delete del;
            }
        }
        return head;
    }
};
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}