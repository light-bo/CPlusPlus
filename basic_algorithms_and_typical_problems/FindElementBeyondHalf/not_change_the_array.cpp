/************************************************
 * 求数组中出现次数超过一半的元素 ***************
 * **********************************************/
int find_beyond_half(int* array, int num) {
	if(NULL==array || num<=0) {
		cout<<"Input error!"<<endl;
		return -1;
	}

	int iResult = array[0];
	int times = 1;

	for(int i=1; i<num; ++i) {
		if(iResult != array[i]) {
			--times;
			if(0 == times) {
				iResult = array[i];
				times = 1;
			}
		} else {
			++times;
		}
	}
	return iResult;
}
