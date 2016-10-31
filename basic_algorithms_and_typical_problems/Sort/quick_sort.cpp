/**
 *  quick sort: 2 partition method
 */
inline void swap(int& x, int& y){
	int temp = x;
	x = y;
	y = temp;
}

int partition_method1(int* array, int low, int high){
	int key = array[low];
	while(low<high){
		while(low<high && array[high]>=key) --high;
		swap(array[low], array[high]);

		while(low<high && array[low]<=key) ++low;
		swap(array[low], array[high]);
	}
	return high;
}

/**
 * this method must take up a extra space(a array element)
 */
int partition_method2(int* array, int low, int high){
	int x = array[high];
	int i = low - 1;

	for(int j=low;j<high;++j){
		if(array[j]<=x){
			++i;
			swap(array[i], array[j]);
		}
	}
	swap(array[i+1], array[high]);
	return i + 1;
}

/** random version partition, the function retrive a random
 * index i of the array, and then swap the element with the index i and
 * the element with the index high, the reason for it is to get the pilot
 * element randomly every time divide the array
 */
int random_partition(int* array, int low, int high){
	int i = low + (rand()%(high-low+1));
	swap(array[i], array[high]);

	return partition_method2(array, low, high);
}

void QuickSort(int* array, int low, int high){
	if(NULL == array)
		return;
	if(low < high){
		int index = partition_method2(array, low, high);
		//int index = random_partition(array, low, high);
		//int index = partition_method1(array, low, high);
		QuickSort(array, low, index-1);
		QuickSort(array, index+1, high);
	}
}
