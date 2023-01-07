class Solution{
public:	
    
	int maxSubstring(string S)
	{
		int n = S.size();

		int arr[n];
		for(int i = 0; i < n; i++)
			arr[i] = (S[i] == '0')?1:-1;

		int cur = arr[0], ans = arr[0];

		for (int i = 1; i < n; i++) 
	   	{ 
	        cur = max(arr[i], cur + arr[i]); 
	        ans = max(ans, cur); 
	   	} 

	   return ans; 
	}	
};
