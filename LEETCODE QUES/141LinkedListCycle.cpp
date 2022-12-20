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
    //     if(head==NULL || head->next==NULL){
    //         return false;
    //     }    
    //     ListNode*temp=head;

    //     while(temp!=NULL){
    //         if(temp->val==INT_MAX){
    //             return true;
    //         }
    //         temp->val = INT_MAX;
    //         temp=temp->next;
    //     }
    //     return false;
    // }


    //By slow and fast method;
         if(head==NULL || head->next==NULL){
            return false;
        }  
        ListNode*slow = head;
        ListNode*fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(fast==slow){
                return true;
            }
        }
        return false;
    }
};
