/***********************************************************
 * left rotate the string, the time complexity is O(n),*****
 * and the space complexity is O(1)                    ***** 
 * ********************************************************/

void reverse(string& str, int low, int high) {
	if(low >= high)
		return;

	while( (low+1) <= high ) {
		char temp = str[low];
		str[low] = str[high];
		str[high] = temp;
		++low;
		--high;
	}
}

void left_rotate_string(string& str, int m) {
	if(str.empty() || m>=str.size())
		return;

	reverse(str, 0, m-1);
	reverse(str, m, str.size()-1);
	reverse(str, 0, str.size()-1);
}

int main() {
	string str;
	int m;
	cin>>str>>m;
	left_rotate_string(str, m);

	cout<<str<<endl;

	return 0;
}



