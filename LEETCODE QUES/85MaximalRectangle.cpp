class Solution {
public:
    vector<int>nextIndx(vector<int>&heigths  , int n){
        stack<int>s;
        s.push(-1);
        vector<int>ans(n,-1);
        for(int i=n-1;i>=0;i--){
            int curr = heigths[i];
            while(s.top()!=-1  && heigths[s.top()]>=curr){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int>prevIndx(vector<int>&heigths  , int n){
        stack<int>s;
        s.push(-1);
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            int curr = heigths[i];
            while(s.top()!=-1  && heigths[s.top()]>=curr){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }

   int MaxHistogram(vector<int>heights,int n ){
       vector<int>nextSmallerIndx(n,0);
       nextSmallerIndx = nextIndx(heights , n);
       vector<int>prevSmallerIndx(n,0);
       prevSmallerIndx = prevIndx(heights , n);
       int maxAns =-1;
       for(int i=0;i<n;i++){
           int len = heights[i];
           int rightIndx = nextSmallerIndx[i];
           if(rightIndx==-1){
               rightIndx =n;
           }
           int leftIndx = prevSmallerIndx[i];
           int breadth = (rightIndx -leftIndx -1);
           int currAns =  len*breadth;
           maxAns = max(maxAns , currAns );

       }
       return maxAns;
   }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
      
        vector<vector<int>>newMatrix(matrix.size(), vector<int>(matrix[0].size(),0));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='1'){
                    newMatrix[i][j]=1;
                }
            }
        }
        vector<int>firstRow = newMatrix[0];
        int n = matrix[0].size();
        int maxAns = MaxHistogram(firstRow,n);
        for(int i=1;i<newMatrix.size();i++){
            for(int j=0;j<newMatrix[0].size();j++){
                if(newMatrix[i][j]!=0){
                    newMatrix[i][j]= newMatrix[i-1][j]+newMatrix[i][j];
                }
                else{
                    newMatrix[i][j]=0;
                }
            }
            int currAns = MaxHistogram(newMatrix[i], n);
            maxAns = max(currAns , maxAns);
        }
        return maxAns;
            } 
};
