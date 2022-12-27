class Solution{
    public:
    //Function to arrange all letters of a string in lexicographical 
    //order using Counting Sort.
    string countSort(string arr){
        // code here
        int n = arr.length();
        string ans="";
        unordered_map<int,int>map;
        for(int i=0;i<n;i++){
            map[arr[i]-'a']++;
        }
        
        int i=0;
        while(i<26){
            if(map[i]>0){
                ans+='a'+ i;
                map[i]--;
            }
            else{
              i++;
            }
        }
        return ans;
    }
};
