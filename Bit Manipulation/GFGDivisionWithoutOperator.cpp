
/*
Given two integers dividend and divisor. Find the quotient after dividing dividend by divisor without using multiplication, division and mod operator.
*/
class Solution
{
    public:
    
    long long divide(long long dividend, long long divisor) {
 
  // Calculate sign of divisor i.e.,
  // sign will be negative only if
  // either one of them is negative
  // otherwise it will be positive
  int sign = ((dividend < 0) ^
              (divisor < 0)) ? -1 : 1;
 
  // remove sign of operands
  dividend = abs(dividend);
  divisor = abs(divisor);
 
  // Initialize the quotient
  long long quotient = 0, temp = 0;
 
  // test down from the highest bit and
  // accumulate the tentative value for
  // valid bit
  for (int i = 31; i >= 0; --i) {
      long long c =(divisor<<i);
    if (temp + (c) <= dividend) {
      temp += c;
      
      quotient |= 1LL << i;
      
    }
    
  }
  //if the sign value computed earlier is -1 then negate the value of quotient
  if(sign==-1) quotient=-quotient;
   
  return quotient;
}
    
};
