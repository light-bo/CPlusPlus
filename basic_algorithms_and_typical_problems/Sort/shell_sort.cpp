/*shell sort method to  sort the array*/

/*a trip shell insert function, array[0] treated as 
 * temporary space to store the smaller element*/
void ShellInsert(int* array, int length, int dk){
	for(int i=1+dk; i<=length; ++i){
		if(array[i] > array[i-dk]){
			array[0] = array[i];
			int j = i - dk;
			for(; j>0 && array[0]<array[j]; j-=dk)
				array[j+dk] = array[j];
			array[j+dk] = array[0];
		}
	}
}

/*the last element of array ds must be 1*/
void ShellSort(int* array, int length, int* ds, int num){
	for(int i=0; i<num; ++i)
		ShellInsert(array, length, ds[i]);
}
