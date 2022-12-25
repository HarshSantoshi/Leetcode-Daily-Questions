class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	  unordered_map<int,int>m;
	  int ans =0;
	  m.insert({0,-1});
	  int sum =0;
	  for(int i=0;i<n;i++){
	      sum+=arr[i];
	      int rem= sum%k;
	      //negative rem
	      while(rem<0)rem=rem+k;
	      
	      //Not present in map
	      if(m.find(rem)==m.end()){
	          m.insert({rem,i});
	      }
	      else{
	          ans=max(ans,i-m[rem]);
	      }
	  }
	  return ans;
	}
};
