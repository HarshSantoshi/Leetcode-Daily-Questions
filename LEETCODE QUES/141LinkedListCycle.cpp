/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL){
            return false;
        }    
        ListNode*temp=head;

        while(temp!=NULL){
            if(temp->val==INT_MAX){
                return true;
            }
            temp->val = INT_MAX;
            temp=temp->next;
        }
        return false;
    }
};
