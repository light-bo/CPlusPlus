/**************************************************
 * find the first character that appear only one  *
 * time in the string, the method is:             *
 *     take advantage of the array to construct a *
 * hashtable that record the info that you can get*
 * it in O(1) time complexity, the time complexity*
 * of the algorithm is O(n).                      *
 * ***********************************************/
char find_first_appear_one_time(const string& str) {
	if(str.size() <= 0)
		return '\0';

	const int arraySize = 256;
	int array[256];
	for(int i=0; i<256; ++i)
		array[i] = 0;

	for(auto it=str.begin(); it!=str.end();
			++it) {
		++array[*it];
	}

	for(auto it=str.begin(); it!=str.end();
			++it) 
		if(1 == array[*it])
			return *it;
	return '\0';
}
