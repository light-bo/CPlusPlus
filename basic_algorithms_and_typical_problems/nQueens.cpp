/*take advantage of traceback method to solve the n queens problems*/
class Solution {
public:
	Solution(int n);
	~Solution();

	void printResult();
	bool isValid(int row);
	void placeQueens(int row);
	void placeAllQueens();

private:
	int sum;
	int* queens;
	int numOfQueens;
};

Solution::Solution(int n) : sum(0), numOfQueens(n),
	queens(new int[n]) {  }

Solution::~Solution() {
	delete []queens;
}

void Solution::printResult() {
	for(int i=0; i<numOfQueens; ++i) {
		for(int  j=0; j<numOfQueens; ++j)
			if(j == queens[i])
				cout<<"!"<<" ";
			else 
				cout<<"0"<<" ";
		cout<<endl;
	}


	cout<<"This is "<<sum<<" solution!"<<endl;
}

void Solution::placeQueens(int row) {
	if(numOfQueens == row) {
		++sum;
		printResult();
		return;
	}

	for(int j=0; j<numOfQueens; ++j) {
		queens[row] = j;
		if(isValid(row))
			placeQueens(row+1);
	}
}

bool Solution::isValid(int row) {
	for(int i=0; i<row; ++i) {
		if(queens[row]==queens[i] ||
				abs(queens[row]-queens[i])==row-i)
			return false;
	}

	return true;
}

void Solution::placeAllQueens() {
	placeQueens(0);
}

