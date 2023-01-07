
/* Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 
Note: The flattened list will be printed using the bottom pointer instead of next pointer.*/


/*
Input:
5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.
Explanation:
The resultant linked lists has every 
node in a single level.
(Note: | represents the bottom pointer.)
*/

class Solution {
public:

    Node * merge(Node* node1 , Node*node2){
        Node*dummy = new Node(-1);
        Node*curr=dummy;
        while(node1!=NULL && node2!=NULL){
            if(node1->data <= node2->data){
                curr->bottom = new Node(node1->data);
                curr=curr->bottom;
                node1=node1->bottom;
            }
            else{
                curr->bottom = new Node(node2->data);
                curr=curr->bottom;
                node2=node2->bottom;
            }
        }
        if(node1!=NULL){
            curr->bottom = node1;
        }
        if(node2!=NULL){
            curr->bottom =node2;
        }
        return dummy->bottom;
    }
    Node *flatten(Node *root)
    {
        // Your code here
        if(root->next==NULL){
            return root;
        }
        Node*result = merge(root , flatten(root->next));
        return result;
    }
};
