class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // int maxLen =0;
        // set<char>set;
        // int start =0;
        // int end =0;
        // int n = s.length();
        // while(start<n){
        //     if(set.find(s[start]) == set.end()){
        //         maxLen=max(maxLen ,start-end+1);
        //         set.insert(s[start]);
        //         start++;
                
        //     }
        //     else{
        //         set.erase(s[end]);
        //         end++;
        //     }
        // }
        // return maxLen;

        
        vector<int>charIndex(256,-1);
        int maxLen =0;
        int lastsame =0;
        int n = s.length();
        for(int i=0;i<n;i++){
            lastsame = max(lastsame , charIndex[s[i]]+1);
            charIndex[s[i]]=i;
            maxLen = max(maxLen  , i-lastsame+1);
        }
        return maxLen;
    }
};
