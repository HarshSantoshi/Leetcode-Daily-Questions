class Solution {
  public:
    int setBits(int n){
        int count =0;
        while(n>0){
            if(n&1){
                count++;
            }
            n=n>>1;
        }
        return count;
    }
    int minVal(int a, int b) {
        // code here
        int seta =setBits(a);
        int setb = setBits(b);
        if(seta==setb){
            return a;
        }
        
        else if(seta>setb){
            int ans=0;
            int rem =setb;
            for(int i=31;i>=0;i--){
                if(a&(1<<i)){
                    ans|=(1<<i);
                    rem--;
                }
                if(rem==0)return ans;
            }
        }
        else{
            int rem = setb - seta;
            int ans =a;
            for(int i=0;i<31;i++){
                if((a&(1<<i))==0){
                    ans|=(1<<i);
                    rem--;
                }
                if(rem==0)return ans;
            }
        }
        
    }
};
