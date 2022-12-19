class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>check;
        for(int i=0;i<s.length();i++){
            check[s[i]]++;
        } 
        for(int j=0;j<s.length();j++){
            if(check[s[j]]>1){
                continue;
            }
            return j;
        }
        return -1;
    }

};