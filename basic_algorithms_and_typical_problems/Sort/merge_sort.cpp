/*merge sort*/
void merge(int* array, int beg, int mid, int end) {
	int i, j, k;
	i = beg;
	j = mid + 1;
	k = 0;
	int* temp = new int[end-beg+1];
	
	while(i<=mid && j<=end) {
		if(array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}

	if(i <= mid) {
		while(i <= mid)
			temp[k++] = array[i++];
	}

	if(j <= end) {
		while(j <= end)
			temp[k++] = array[j++];
	}

	for(int x=beg, y=0; x<=end; ++x, ++y)
		array[x] = temp[y];

	delete []temp;
}

void merge_sort(int* array, int beg, int end) {
	if(NULL==array || beg>=end)
		return;
	int mid = beg + ((end-beg)>>1);//pay attention to the primary
	                               //of the operator

	merge_sort(array, beg, mid);
	merge_sort(array, mid+1, end);

	merge(array, beg, mid, end);
}
