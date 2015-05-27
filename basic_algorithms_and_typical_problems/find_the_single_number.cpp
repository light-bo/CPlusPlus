/*有2n + 1 个数，其中除了一个数以外，其他的数两两相等，找出
 * 这个数。采用的方法是：将所有的数进行异或，这样以来，相同
 * 的数会相互抵消，最后的结果就是那个要找的数！*/

int find_the_single_number(int* array, int length) {
	if(NULL==array || length<=2 || !(length&0x1)) {
		throw	invalid_argument("invalid input"); 
	}
	
	int temp = array[0];
	for(int i=1; i<length; ++i) 
		temp ^= array[i];

	return temp;
}
