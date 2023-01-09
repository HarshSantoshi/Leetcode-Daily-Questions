
/*
Given a Binary search Tree that contains positive integer values greater then 0. The task is to complete the function isDeadEnd 
which returns true if the BST contains a dead end else returns false. Here Dead End means, we are not able to insert any element after that node.

Examples:

Input :   
               8
             /   \ 
           5      9
         /  \     
        2    7 
       /
      1     
          
Output : Yes
Explanation : Node "1" is the dead End because after that 
              we cant insert any element.  
*/

void store(Node*root  ,unordered_set<int>&allNodes ,unordered_set<int>&leafNodes ){
    if(root==NULL)return ;
    
    allNodes.insert(root->data);
    if(root->left==NULL && root->right == NULL){
        leafNodes.insert(root->data);
    }
    store(root->left , allNodes , leafNodes);
    store(root->right , allNodes , leafNodes);
    return ;
}
bool isDeadEnd(Node *root)
{
    //Your code here
    unordered_set<int>allNodes;
    unordered_set<int>leafNodes;
    store(root , allNodes , leafNodes);
    allNodes.insert(0);
    
   for (auto i = leafNodes.begin() ; i != leafNodes.end(); i++){
        int ele = (*i);
        if(allNodes.find(ele+1)!=allNodes.end() && allNodes.find(ele-1) !=allNodes.end()){
            return true;
        }
    }
    return false;
}
