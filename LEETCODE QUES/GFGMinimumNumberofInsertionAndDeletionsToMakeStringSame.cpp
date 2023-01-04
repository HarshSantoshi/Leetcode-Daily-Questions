class Solution{
		

	public:
	int dp[1001][1001];
	int LCS(string str1 , string str2 , int l1 , int l2){
	    if(l1==0 || l2==0){
	        return 0;
	    }
	   for(int i=0;i<l1+1 ;i++){
	       for(int j=0;j<l2+1;j++){
	           if(i==0 || j==0){
	               dp[i][j]=0;
	           }
	           else if(str1[i-1]==str2[j-1]){
	               dp[i][j]= 1+ dp[i-1][j-1];
	           }
	           else{
	               dp[i][j]= max(dp[i-1][j] , dp[i][j-1]);
	           }
	       }
	   }
	   return dp[l1][l2];
	}
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int l1 = str1.length();
	    int l2 = str2.length();
	    int lengthofLCS = LCS(str1 , str2 , l1 , l2);
	    int deletions = l1-lengthofLCS;
	    int insertions = l2 - lengthofLCS;
	    int ans = deletions + insertions ;
	    return ans;
	    
	} 
};
