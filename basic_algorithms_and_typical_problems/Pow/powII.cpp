/*******************************************************
 * 算法思路：                                        ***
 * 	如果 n 为偶数，则                              ***
 * 		pow(x, n) = pow(x, n>>1) * pow(x, n>>1)     ***
 * 	若 n 为奇数,则                                 ***
 * 		如果 n > 0:                                 ***
 * 			pow(x, n) = pow(x, n>>1) * pow(x, n>>1)  ***
 * 				* x                                   ***
 * 		若 n < 0：                                  ***
 * 			pow(x, n) = pow(x, n>>1) * pow(x, n>>1)  ***
 * 				/ x                                   ***
 * ****************************************************/

class Solution {
public:
    double pow(double x, int n) {
       if(0==x && n<0)
         throw invalid_argument("invalid input!");
         
       if(0 == n)
        return 1;
         
       double temp = pow(x, n/2);
       if(0 == n%2) {
           return temp * temp;
       }else {
           if(n > 0)
            return temp * temp * x;
           else 
            return temp * temp / x;
       }
    }
};
