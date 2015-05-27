/*数组先增加后减少，求数组的最大元素*/
int find_max(int* array, int low, int high) {
	if(NULL==array || low>high)
		throw invalid_argument("The array is empty!");

	if(low == high) 
		return 0;
	if(2 == (high-low+1))
		return array[0] >= array[1] ?
			0 : 1;

	while(low <= high) {
		int mid = low + (high-low)/2;
		if(0==mid || high==mid)
			return mid;

		if(array[mid-1]<=array[mid] && 
				array[mid+1]<=array[mid])
			return mid;

		if(array[mid-1] < array[mid])
			low = mid + 1;
		else if(array[mid+1] < array[mid])
			high = mid - 1;
	}
}

int find_max(int* array, int size) {
	return find_max(array, 0, size-1);
}
