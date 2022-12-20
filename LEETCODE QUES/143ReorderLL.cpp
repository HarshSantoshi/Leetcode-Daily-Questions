class Solution {
public:
     void reorderList(ListNode* head) {
        //base case 
        //If LL has 0 , 1 or 2 nodes just return 
        if(!head || !head->next || !head->next->next) return;
        
        //Find the secondLastNode node 
        ListNode* secondLastNode = head;
        while (secondLastNode->next->next)secondLastNode = secondLastNode->next;
        
        // Link the secondLastNode with the second element from start
        secondLastNode->next->next = head->next;
        head->next = secondLastNode->next;
        
        //Again set the secondLastNode to the the last 
        secondLastNode->next = NULL;
        
        // Do the above steps recursive
        reorderList(head->next->next);
    }
};
