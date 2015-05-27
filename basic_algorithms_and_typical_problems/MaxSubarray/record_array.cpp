//本算法时间复杂度为O(n),算法从左到右遍历数组，用一个辅助数组
//记录目前为止所处理的最大子数组，最后遍历一遍记录的数组，找
//到最大的子数组

Result max_subarray(int* array, int low, int high){
	if(NULL==array || low>=high)
		cout<<"invalid input"<<endl,exit(-1);

	Result* subarray = new Result[high-low];	

	//initialize the record array
	subarray[low].left = low;
	subarray[low].right = low + 1;
	subarray[low].sum = array[low];

	//if the sum of the preve record is less than 0,
	//then re-record it
	for(int i=low+1;i<high;++i){
		if(subarray[i-1].sum < 0){
			subarray[i].left = i;
			subarray[i].right = i + 1;
			subarray[i].sum = array[i];
		}else{
			Result* preve = &subarray[i-1];
			subarray[i].left = preve->left; 
			subarray[i].right = i+1; 
			subarray[i].sum = preve->sum + array[i];
		}
	}
	
	//find the max result
	Result maxSubarray = subarray[low];

	for(int i=low+1;i<high;++i){
		if(subarray[i].sum > maxSubarray.sum)
			maxSubarray = subarray[i];
	}

	delete []subarray;

	return maxSubarray;
}
