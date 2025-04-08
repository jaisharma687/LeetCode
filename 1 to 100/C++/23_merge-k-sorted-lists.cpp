#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* merge(ListNode* list1, ListNode* list2){
            ListNode* head = new ListNode();
            ListNode* temp = head;
            while(list1!=NULL && list2!=NULL){
                if(list1->val <= list2-> val){
                    temp->next = list1;
                    list1 = list1->next;
                }
                else{
                    temp->next = list2;
                    list2 = list2->next;
                }
                temp = temp->next;
            }
            if(list1!=NULL) temp->next = list1;
            if(list2!=NULL) temp->next = list2;
            return head->next;
        }
        ListNode* recursiveMergeList(vector<ListNode*>& lists, int start, int end){
            if (start > end) return nullptr;
            if(start==end) return lists[start];
            int mid = start + (end-start)/2;
            return merge(recursiveMergeList(lists,start,mid),recursiveMergeList(lists,mid+1,end));
        }
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            return recursiveMergeList(lists,0,lists.size()-1);
        }
    };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();