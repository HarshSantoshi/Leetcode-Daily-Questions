class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
       stack<int>st;
       for(int i=0;i<n;i++){
           st.push(i);
       }
       while(st.size()>1){
           int A = st.top();
           st.pop();
           int B = st.top();
           st.pop();
           if(M[A][B]==1){
               st.push(B);
           }
           else if( M[B][A]==1){
               st.push(A);
           }
       }
       int count=0;
       for(int i=0;i<n;i++){
           if(M[st.top()][i]==1){
               return -1;
           }
           else{
               count++;
           }
       }
       if(count!=n){
           return -1;
       }
       int count1=0;
       for(int j=0;j<n;j++){
           if(M[j][st.top()]==0 && j!=st.top()){
               return -1;
           }
           else if(M[j][st.top()]==1){
               count1++;
           }
       }
       if(count1!=n-1)return -1;
       return st.top();
    }
};
