class Solution
{
  public:
  int maxWeightCell(int N, vector<int> Edge)
  {
      // code here
     vector<int>wt(N,0);
      for(int i=0;i<N;i++){
          if(Edge[i]!=-1)
          wt[Edge[i]]+=i;
      }
     int maxwt =-1;
     int ans=-1;
     for(int i=0;i<N;i++){
         if(maxwt<=wt[i]){
             maxwt =wt[i];
             ans=i;
         }
     }
     return ans;
      
  }
};
