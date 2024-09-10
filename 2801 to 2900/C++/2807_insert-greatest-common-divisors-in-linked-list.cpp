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
    int gcd(int a, int b){
        if(b==0) return a;
        else return gcd(b,a%b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* a = head->next;
        ListNode* b = head;
        while(a!=nullptr){
            int value = (a->val > b->val) ? gcd(a->val,b->val) : gcd(b->val,a->val);
            ListNode* mid = new ListNode(value,a);
            b->next = mid;
            b = a;
            a = a->next;
        }
        return head;
    }
};