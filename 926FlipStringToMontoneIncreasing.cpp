
/*A binary string is monotone increasing if it consists of some number of 0's (possibly none), followed by some number of 1's (also possibly none).

You are given a binary string s. You can flip s[i] changing it from 0 to 1 or from 1 to 0.

Return the minimum number of flips to make s monotone increasing.

 Input: s = "010110"
Output: 2
Explanation: We flip to get 011111, or alternatively 000111.
*/


class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int count1=0;
        int count0 =0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1')count1++;
            else count0++;

            count0= min(count0 , count1);
        }
        return count0;
    }
};
