#include<iostream>
#include<vector>
using namespace std;
    int isPalindrome(string s) {
        // if(s==" "){
        //     return true;
        // }  
        string ans;
        int n = s.length();
        int m=0;
        for(int i=0;i<n;i++){
            if(s[i]>='A' && s[i]<='Z'){
                ans[m]=s[i]-32;
                m++;
            }
            else if(s[i]>='a' && s[i]<='z'){
                ans[m]=s[i];
                m++;
            }
            else{
                i++;
            }
        }
        // int l = ans.size();
        // // amanaplanacanalpanama
        // int start =0;
        // int end = l-1;
        // while(start<=end){
        //     if(ans[start]!=ans[end]){
        //         return false;
        //     }
        //     start++;
        //     end--;
        // } 
        // return true;
        return m;
    }
    // A man, a plan, a canal: Panama

    int main(){
        string s;
        cin>>s;
        // if(isPalindrome){
        //     cout<<"True";
        // }
        // else{
        //     cout<<"False";
        // }
        int a =isPalindrome(s);
        cout<< a;
        // for(int i=0;i<ans.size();i++){
        //     cout<<ans[i];
        // }
    }
