/************************************************************
 *    给定一个二维数组，该数组的每一行从左到右递增，没   ****
 *一列从上到下递增，在该数组中查找给定的数，如果找到，则 ****
 *返回 true，否则返回 false。                            ****
 ***********************************************************/

/*find the value begin from the top right element*/
bool find_value_from_top_right(int* array, int rows, int columns, int value) {
     bool bResult = false;
     if(NULL!= array && rows>0 && columns>0) {
		  int row = 0;
		  int column = columns - 1;
		  while(row<rows && columns>=0) {
			  if(value == array[row*columns + column]) {
				  bResult = true;
				  break;
			  } else if(value < array[row*columns + column])
				  --column;
			  else
				  ++row;
		  }
	  }

	  return bResult;
}

/*find the value begin from the bottom left element*/
bool find_value_from_bottom_left(int* array, int rows, int columns, int value) {
	bool bResult = false;
	if(NULL!= array && rows>0 && columns>0) {
		int row = rows - 1;
		int column = 0;
		while(row>=0 && column<columns) {
			if(value == array[row*columns + column]) {
				bResult = true;
				break;
			} else if(value > array[row*columns + column])
				++column;
			else
				--row;
		}
	}

	return bResult;
}

