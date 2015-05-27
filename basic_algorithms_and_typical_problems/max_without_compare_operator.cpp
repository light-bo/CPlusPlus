/******************************************************************
 * compare two numbers without compare operator,the mechanism******
 * of it is:                                                  ***** 
 *     make k is the sign of x - y,easy to know the x - y is  ***** 
 *     1 or 0, then return the result x - k * (x-y)           ***** 
 ******************************************************************/

int max_without_compare_operator(int x, int y) {
	int c = x - y;
	int k = (c>>31) & 0x1;
	return x - k * c;
}
