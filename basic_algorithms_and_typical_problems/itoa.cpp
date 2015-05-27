/*itoa*/
char* itoa(char* str, int val) {
	if(NULL==str)
		return NULL;
	int i = 0;
	bool positive = false;
	
	if(val < 0) {
		str[i++] = '-';
		positive = true;
		val = -val;
	}
	
	if(0 == val) {
		str[i++] = '0';
	}

	while(val) {
		str[i++] = val % 10 + '0';
		val /= 10;
	}

	str[i] = '\0';

	if(positive) 
		reverse(str+1, str+i);
	else
		reverse(str, str+i);

	return str;
}
