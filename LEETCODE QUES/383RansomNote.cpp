class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>ransommap;
        unordered_map<char,int>magazinemap;
       
        for(int i=0;i<magazine.length();i++){
            magazinemap[magazine[i]]++;
        }       
        for(int j=0;j<ransomNote.length();j++){
            if(magazinemap[ransomNote[j]]>0){
                magazinemap[ransomNote[j]]--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};