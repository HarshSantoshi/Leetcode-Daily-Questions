class Solution {
public:
    bool detectCapitalUse(string word) {
        int capCount=0;
        int smallCount=0;
        for(int i=0;i<word.size();i++){
            if(word[i]>='A' && word[i]<='Z'){
                capCount++;
            }
            else{
                smallCount++;
            }
        }
        if(capCount==word.size()){
            return true;
        }
        if(smallCount ==word.size()){
            return true;
        }
        if(word[0]>='A' && word[0]<='Z' && smallCount==word.size()-1)return true;

        return false;
    }
};
