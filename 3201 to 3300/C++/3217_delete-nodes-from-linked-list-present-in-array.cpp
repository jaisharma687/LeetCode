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
    void deleteNode(ListNode*& head, unordered_set<int> values){
        if(head==nullptr) return;
        ListNode cur = ListNode(0,head);    // 'cur' is an object, not a pointer
        ListNode * ptr = &cur;              // 'ptr' is a pointer to 'cur'
        while(ptr->next != nullptr){
            if(values.contains(ptr->next->val)){
                ptr->next = ptr->next->next;
            }else ptr = ptr->next;
        }
        head = cur.next;
    }
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> valuesToDelete(nums.begin(), nums.end());
        deleteNode(head,valuesToDelete);
        return head;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}