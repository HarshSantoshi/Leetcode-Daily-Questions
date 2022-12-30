/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
//93

// 32 433 636 121 831 102 695 509 104 776 905 876 219 202 326 393 141
//752 504 109 640 765 537 759 971 857 147 716 897 484 60 928 268 47 48 
//98 500 94 607 603 221 863 831 439 416 156 183 556 259 686 16 250 450 
//552 9 772 409 155 487 305 990 898 232 258 945 631 707 444 724 313 47 
//296 527 229 734 942 736 268 849 995 953 865 244 754 416 604 526 176 
//110 364 832 100 262
class Solution
{
    public:
    
Node* reverse(Node* head)
{
    Node *prev = NULL;
    Node *curr = head, *next;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
    Node *compute(Node *head)
    {
        // your code goes here
        head = reverse(head);
        Node*curr =head->next;
        Node*prev = head;
        int mx = head->data;
        while( curr!=NULL){
            if(curr->data<mx){
                Node*temp= curr;
                prev->next = curr->next;
                curr=curr->next;
                delete temp;
                
            }
            else{
                mx = curr->data;
                prev = curr;
                curr=curr->next;
            }
        }
        head = reverse(head);
        return head;
    }
};
