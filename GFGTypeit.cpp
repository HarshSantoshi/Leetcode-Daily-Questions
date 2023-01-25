class Solution {
  public:
    int minOperation(string s) {
        // code here
        int n = s.size();
        if(n<=3){
            return n;
        }
        
        for(int i=n/2;i>=0;i--){
            if(s.substr(0,i+1) == s.substr(i+1,i+1)){
                return (i+1 + 1 + n-(2*i+2));
            }
        }
        return n;
    }
};
