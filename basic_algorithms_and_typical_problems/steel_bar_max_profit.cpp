/*动态规划法解决钢条的最大收益问题*/
inline int max(int x, int y) {
	return x > y ? x : y;
}

int max_profit(int* p, int n, int* r);

/*自顶向下*/
int max_profit_top_to_bottom(int* p, int n) {
	if(NULL==p || n<0)
		return -1;
	
	int* r = new int[n+1];
	for(int i=0; i<=n; ++i) {
		r[i] = ~0x7fffffff;
	}
	
	int maxProfit = max_profit(p, n, r);

	delete []r;

	return maxProfit;
}

int max_profit(int* p, int n, int* r) {
	if(r[n] >= 0)
		return r[n];

	if(0 == n)
		return 0;
	else {
		int q = ~0x7fffffff;
		for(int i=1; i<=n; ++i)
			q = max(q, p[i] + 
					max_profit(p, n-i, r));
		r[n] = q;
		return q; 
	}
}

/*从底向上*/
int max_profit_bottom_to_top(int* p, int n) {
	//apply for a array for record
	int* r = new int[n+1];

	//initializ the array
	r[0] = 0;

	//from bottom to top to get the max profit
	if(0 == n)
		return 0;
	else {
		int j;
		for(j=1; j<=n; ++j) {
			int q = ~0x7fffffff;
			for(int i=1; i<=j; ++i) {
				q = max(q, p[i] + r[j-i]);
			}
			r[j] = q;
		}
	}

	int result = r[n];
	delete []r;
	return result;
}
