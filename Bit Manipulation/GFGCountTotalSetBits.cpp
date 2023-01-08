
/*
You are given a number N. Find the total count of set bits for all numbers from 1 to N(both inclusive).
T.C =O(logn)
*/
class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int powerLess(int n){
        int x=0;
        while(1<<x <=n){
            x++;
        }
        return x-1;
    }
    int countSetBits(int n)
    {
        if(n==0){
            return 0;
        }
        int x = powerLess(n);//Find power of 2 which is just less than n
        int sumofBitsTill2raisex =x*(1<<(x-1));
        int Excluded1 = (n-(1<<(x)) +1) ;
        // x*(2^(x-1)) + (n-2^x +1) + call for rest
        int res = sumofBitsTill2raisex +Excluded1+ countSetBits(n-(1<<x));
        return res;
    }
};
