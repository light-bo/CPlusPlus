/*KMP algorithm to solve the pattern matching problem*/

/*get the next array: 当前位置发生不匹配时，应该回到哪个位置*/
void GetNext(const string& ps, int* next){
	int strLen = ps.size();
	int k = -1; //suffix
	int j = 0;  //prefix
	next[0] = -1;

	while(j < (strLen -1)){
		if((-1==k) || (ps[k]==ps[j])){
			++j;
			++k;
			next[j] = k;
		}else
			k = next[k];
	}
}

int PatternMatching(const string& ts, const string& ps){
	int tsLen = ts.size();
	int psLen = ps.size();
	int* next = new int[psLen];
	int i(0);
	int j(0);

	GetNext(ps, next);

	while(i<tsLen && j<psLen){
		if((-1==j) || (ts[i]==ps[j])){
			++i;
			++j;
		}else
			j = next[j];
	}
	
	delete []next;

	if(j == psLen)
		return  i - j;
	else
		return -1;
}
