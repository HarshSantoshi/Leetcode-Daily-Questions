class Solution {
public:
    int lengthOfLastWord(string s) {
        int count =0;
        bool first =true;
        for(int i=s.length()-1;i>=0;i--){
            while(s[i]== ' ' && first ){
                i--;
            }
            first = false;
            if(s[i]!=' '){
                count++;
            }
            else{
                return count;
            }
        }
        return count;
    }
};
