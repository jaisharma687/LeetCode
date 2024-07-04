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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* nxt = head;
        ListNode* t1 = list1;
        ListNode* t2 = list2;
        while(t1 != NULL && t2 != NULL){
            nxt->next = new ListNode((t1->val < t2-> val)?t1->val:t2->val);
            if(t1->val < t2->val) t1 = t1->next;
            else t2 = t2->next;
            nxt = nxt->next;
        }
        while(t1 != NULL){
            nxt->next = new ListNode(t1->val);
            t1 = t1->next;
            nxt = nxt->next; 
        }
        while(t2 != NULL){
            nxt->next = new ListNode(t2->val);
            t2 = t2->next;
            nxt = nxt->next;
        }
        return head->next;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}