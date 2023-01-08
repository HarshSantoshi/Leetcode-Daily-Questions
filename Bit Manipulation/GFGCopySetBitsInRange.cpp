/*
Given two numbers x and y, and a range [l, r] where 1 <= l, r <= 32. Find the set bits of y in range [l, r] and set these bits in x also.
*/

class Solution{
    public:
    int setSetBit(int x, int y, int l, int r){
        // code here
        // if(l<1 || r>32)return ;
        for(int i=l;i<=r;i++){
            //a bitMask has only one set bit
            int bitMask= (1<<(i-1));
            if(bitMask & y){
                //If bit is set then add it in x
                x= x| bitMask;
            }
        }
        return x;
    }
};
