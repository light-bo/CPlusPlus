/**********************************************************
 * 实现库函数中的 pow 函数， 重点在于以下公式的使用：     *
 *  a(n) = a(n^2) * a(n^2)  偶数                          *
 *       = a((n-1)/2) * a((n-1)/2) * a  奇数              *
 *********************************************************/
bool g_invalid = false;
double power_with_unsigned_exp(double base, unsigned exp) {
	if(0 == exp)
		return 1;
	if(1 == exp)
		return base;

	double dResult = power_with_unsigned_exp(base, exp>>1);
	dResult *= dResult;

	if( 1 == (exp & 0x1) )
		dResult *= base;

	return dResult;
}


double my_pow(double base, int exp) {
	double dResult = 1;
	if(0==base && exp<0) {
		g_invalid = true;
		return dResult;
	}
	
	unsigned unsignedExp = abs(exp);

	dResult = power_with_unsigned_exp(base, unsignedExp);

	if(exp < 0)
		dResult = 1/dResult;

	return dResult;
}
