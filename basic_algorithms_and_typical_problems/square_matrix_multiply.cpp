//本算法采用“直接法”计算 n 阶矩阵的乘法问题，时间复杂度为O（n^3)
//其中，矩阵用一个一维数组表示

int* square_matrix_multiply(int* A, int* B, int n){
	if(NULL==A || NULL==B)
		return NULL;

	int* C = new int[n*n];
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			C[i*n+j] = 0;
			for(int k=0;k<n;++k)
				C[i*n+j] += (A[i*n+k] * B[(k*n)+j]);
		}
	}

	return C;
}
