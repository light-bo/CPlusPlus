/* Heap Sort: the time complexity is O(nlgn)*/

/*adjust the array to max heap with specific index*/
void max_heapify(int* array, int index, int heapSize){
	//get children' indexs of the node with specific index
	int leftIndex = 2 * index;
	int rightIndex = 2 * index + 1;

	//get the lardest index
	int largest = index;
	if(leftIndex <= heapSize &&
			array[leftIndex] > array[index])
		largest = leftIndex;
	else
		largest = index;

	if(rightIndex <= heapSize &&
			array[rightIndex] > array[largest])
		largest = rightIndex;
	
	//swap the values and adjust the 
	//child tree recursively
	if(largest != index){
		int temp = array[largest];
		array[largest] = array[index];
		array[index] =temp;
		max_heapify(array, largest, heapSize);
	}
}

/*take advantage of all not leaf nodes to build a max heap*/
void build_max_heap(int* array, int heapSize){
	for(int i=heapSize/2;i>=1;--i)
		max_heapify(array, i, heapSize);
}


void heap_sort(int* array, int heapSize){
	//build the array to a max heap
	build_max_heap(array, heapSize);

	//swap the max value with the last value
	for(int i=heapSize;i>=2;--i){
		int temp = array[1];
		array[1] = array[i];
		array[i] = temp;
      --heapSize;
		max_heapify(array, 1, heapSize);
	}
}

