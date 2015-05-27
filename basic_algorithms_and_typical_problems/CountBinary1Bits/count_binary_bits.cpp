/*计算输入整数所含有的二进制位数*/

/*输入整数 n 不动，不断移动 flag 判断不同的位，统计结果*/
int count1(int n) {
	int c = 0;
	unsigned int flag = 1;
	while(flag) {
		if(n & flag) 
			++c;
		flag <<= 1;
	}

	return c;
}

/*一个整数减去1之后和原来的整数进行与运算后，会“消去”*
 *原有整数二进制表示中的最右边的一个1*/
int count2(int n) {
	int c = 0;
	while(n) {
		++c;
		n = (n-1) & n;
	}
	return c;
}

