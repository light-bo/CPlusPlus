/*****************************************************
 * erase the odd numbers in the input vector, pay  ***
 * attention to that erase function will auto move ***
 * the iterator to the position of the next element***
 * **************************************************/

void erase_odd(vector<int>& ivect) {
	vector<int>::iterator it = ivect.begin();

	while(it != ivect.end()){
		if(0 == (*it % 2))
			++it;
		else
			ivect.erase(it);
	}
}
