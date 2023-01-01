class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char , string>m1;
        unordered_map<string, char>m2;
        int start =0;
        int end =0;

        for(int i=0;i<pattern.length();i++){
            string sub;
            if(i!=pattern.length()-1){
                end = s.find(' ',start);
                sub = s.substr(start , end-start);
            }
            else{
                sub = s.substr(start,s.length()-start);
            }
            if(sub==""){
                return false;
            }
            if(!m1.count(pattern[i])){
                m1[pattern[i]]=sub;
            }
            if(!m2.count(sub)){
                m2[sub]=pattern[i];
            }

            if(m1[pattern[i]] != sub || m2[sub]!=pattern[i]){
                return false;
            }
            start = end+1;
        }
        return true;
    }
};
