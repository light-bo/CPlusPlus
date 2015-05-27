/*typical binary search algorithm*/
int BinarySearch(int* array, int val){
	int low = 1;
	int high = array[0];//store the length of the array
	int mid;
	while(low <= high){
		mid = low + (high-low)/2;//avoid overflow
		if(val == array[mid])
			return mid;
		else if(array[mid] > val)
			high = mid - 1;
		else if (array[mid] < val)
			low = mid + 1;
	}

	return -1;
}

