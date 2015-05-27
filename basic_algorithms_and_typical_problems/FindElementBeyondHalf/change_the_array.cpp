/*****************************************************
 * take advantage of the partition function to  ******
 * solve the problem, the time complexity is O(n), ***
 * but the method has changed the input array .   ****
 * 原理：如果一个元素在一个数组中出现的次数超过   ****
 * 数组元素个数的一半， 则调用 partition 函数后 ******
 * 返回的下标为 n/2 的元素就是要找的元素       *******
 * **************************************************/
void swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

int partition(int* array, int low, int high) {
	int pilot = array[low];

	while(low <high) {
		while(low<high && pilot<=array[high]) --high;
		swap(array[low], array[high]);

		while(low<high && pilot>=array[low]) ++low;
		swap(array[low], array[high]);
	}

	return high;
}

int find_value_beyond_half(int* array, int low, int high) {
	//the element with the index n/2 must be 
	//the value we want to find
	int mid = low + (high-low)/2;
	int start, end;
	start = low;
	end = high;

	int index = partition(array, start, end);

	while(index != mid) {
		if(index > mid) {
			end = index - 1;
			index = partition(array, start, end);
		} else {
			start = index + 1;
			index = partition(array, start, end);
		}
	}
	
	return array[index];
}

