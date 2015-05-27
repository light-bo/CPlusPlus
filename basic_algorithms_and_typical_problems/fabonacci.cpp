/*A good method to solve the fabonacci problem*/
#include <iostream>
using namespace std;

class Solution {
public:
	void fabonacciLimit(int iLimit) {
		int pre, cur;
		pre = cur = 1;
		cout<<pre<<endl;
		while(cur <= iLimit) {
			cout<<cur<<endl;
			cur = pre + cur;
			pre = cur - pre;
		}
	}

	int fabonacciSpecificItem(int n) {
		if(n <= 0)
			return -1;
	    int pre, cur;
		pre = cur = 1;

		for(int i=2; i<n; ++i) {
			cur += pre;
			pre = cur - pre;
		}

		return cur;
	}
};
