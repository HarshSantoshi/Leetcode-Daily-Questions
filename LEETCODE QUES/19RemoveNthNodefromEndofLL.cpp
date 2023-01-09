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
 
 /*Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*start = new ListNode(0);
        
        ListNode*slow = start ;
        ListNode*fast = start;
        start->next = head;
        
        for(int i=0;i<=n;i++){
            fast=fast->next;
        }
        while(fast!=NULL){
            slow =slow->next;
            fast = fast->next;
        }
        ListNode*toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;
        
        return start->next;
    }
   
};
