
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //Below code has T.C=O(n*m)
       
        // string ans ="";
    //     for(int i=0;i<strs[0].size();i++)
    //     {
    //         char ch = strs[0][i];
    //          bool check = true;
    //         for(int j=1;j<strs.size();j++){
               
    //             if(strs[j][i]!=ch){
    //                 check = false;
    //                 break;
    //             }           
    //         }
    //         if(check==false){
    //             break;
    //         }
    //         ans.push_back(ch);
    //     }
    //     return ans;
    // }





    //Below code has T.C =O(n*logn)
   
    string ans ="";
      int n = strs.size();
        if(n==0) return "";
    
    // sort(strs.begin().strs.end());
     sort(begin(strs), end(strs));


    string a = strs[0];
    string b = strs[n-1];
    for(int i=0;i<a.size();i++){
        if(a[i]==b[i]){
            ans=ans+a[i];
        }
       else  break;
    }
    return ans;
    }
};
