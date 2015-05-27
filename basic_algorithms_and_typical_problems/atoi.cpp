/*将数字的字符串转化为整数，不考虑整数的溢出问题*/
int atoi(string& str) {
	if( 0 == str.length() )
		throw invalid_argument("The string is empty!!");

	string::iterator it = str.begin();
	bool bNegative = false;
	if('+' == (*it)) {
		++it;
	} else if('-' == (*it)) {
		++it;
		bNegative = true;
	}

	if( it == str.end() ) 
		throw invalid_argument("invalid input!!");
	
	int iResult = 0;
	for(; it!=str.end(); ++it) {
		if( (*it)>=48 && (*it)<=57) {
			iResult = (iResult*10 + (*it) - '0');
		} else 
			throw invalid_argument("invalid input!!");
	}

	if(bNegative)
		iResult = -iResult;

	return iResult;
}
