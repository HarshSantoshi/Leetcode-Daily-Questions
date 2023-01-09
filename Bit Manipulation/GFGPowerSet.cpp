
/*
Given a string S, Find all the possible subsequences of the String in lexicographically-sorted order.

Example 1:

Input : str = "abc"
Output: a ab abc ac b bc c
Explanation : There are 7 subsequences that 
can be formed from abc.
*/

class Solution{
	public:
// 	void solve(vector<string>&ans , string s , int index, string output ){
// 	    if(index>=s.length()){
// 	        if(output.length()!=0){
// 	            ans.push_back(output);
// 	        }
// 	        return ;
// 	    }
	    
// 	    solve(ans  , s , index+1  , output);
	    
// 	    solve(ans , s , index+1 , output+s[index]);
// 	    return;
// 	}

	vector<string> AllPossibleStrings(string s){
		    // Code here
		  //  vector<string>ans;
		  //  string output = "";
		  //  solve(ans , s , 0 ,output);
		  //  sort(ans.begin(), ans.end());
		  //  return ans;
		  
		  //With Bit Manipulation
		    vector<string>a1;
		    int n=(1<<(s.size()));//2^(s.size())
		    for(int j=1;j<n;j++)
		    {
		       string s1="";
		       int x=j;
		       int i=0;
		       while(x)
		       {
		           if(x&1)
		           {
		               s1+=s[i];
		           }
		           i++;
		           x=x>>1;
		       }
		        a1.push_back(s1);
		    }
		    sort(a1.begin(),a1.end());        //a b ab c ac bc abc
		    return a1;
	}
	
};
