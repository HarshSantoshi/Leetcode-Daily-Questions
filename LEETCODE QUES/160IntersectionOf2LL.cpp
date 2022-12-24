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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
        // //O(m*n)
        // ListNode *temp;
		// while(headA != NULL){
		// 	temp = headB;
		// 	while(temp != NULL){
		// 		if(headA == temp){
		// 			return headA;
		// 		}
		// 		temp = temp -> next;
		// 	}
		// 	headA = headA -> next;
		// }
		// return NULL;


        //Using MAP
        // unordered_map<ListNode*,int>map;
        // while(headA!=NULL)
        // {
        //     map[headA]++;
        //     headA=headA->next;
        // }
        // while(headB!=NULL)
        // {
        //     if(map[headB]>0)return headB;
        //     headB = headB->next;
        // }
        // return NULL;



        //O(m+n)  S.C = O(1)


        ListNode *ptr1 = headA;
		ListNode *ptr2 = headB;
		while(ptr1 != ptr2){
			if(ptr1 == NULL){
				ptr1 = headB;
			}
			else{
				ptr1 = ptr1 -> next;
			}
			if(ptr2 == NULL){
				ptr2 = headA;
			}
			else{
				ptr2 = ptr2 -> next;
			}
		}
		return ptr1;
    }
};
