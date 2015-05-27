/*use the brute force method to solve the pattern matching problem*/
int pattern_matching(const string& ts, const string& ps){
	int i, j;
	i = j = 0;
	int tsLen = ts.size();
	int psLen = ps.size();

	while(i<tsLen && j<psLen){
		if(ts[i] == ps[j]){
			++i;
			++j;
		}else{
			i = i - j + 1;//i backtrace
			j = 0;        //set j to 0
		}
	}

	if(j == psLen)
		return i - j;
	else
		return -1;
}
