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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head;
        ListNode* new_list = new ListNode();
        ListNode* head2 = new_list;
        int s = 0;
        while(temp != NULL){
            if(temp->val == 0 && temp != head){
                new_list->next = new ListNode(s);
                new_list = new_list->next;
                s = 0;
            }else{s += temp->val;}
            temp = temp->next;
        }
        return head2->next;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}