
/*
Given a number N having only one ‘1’ and all other ’0’s in its binary representation, find position of the only set bit. 
If there are 0 or more than 1 set bit the answer should be -1.
Position of  set bit '1' should be counted starting with 1 from LSB side in binary representation of the number.
*/
class Solution {
  public:
    int findPosition(int N) {
        // code here
        int i=1;
        int ans=-1;
        bool flag =false;
        while(N>0){
            
            if(N&1 && flag==false){
                flag =true;
                ans=i;
            }
            else if(N&1 && flag==true){
                ans=-1;
                break;
            }
            N=N>>1;
            i++;
        }
        return ans;
    }
};
