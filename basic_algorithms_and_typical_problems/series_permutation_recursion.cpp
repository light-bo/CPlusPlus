//求解一个数列的全排列的递归解法:采用的是分治法
template <typename T>
void Swap(T& a,T& b)
{
	if(a == b)
		return;

	T temp;
	temp=a;
	a=b;
	b=temp;
}

template <typename T>
void Permutation(T array[],T beg,T end)
{
	//若分割的序列只剩下一个元素，则该序列已经选择完成，显示序列
	if(beg==end)
	{
		for(T i=0;i<=end;++i)
			cout<<array[i]<<" ";
		cout<<endl;
	}else
	{
		//保持序列最左边的元素不变，递归求剩下序列的全排列
		for(T i=beg;i<=end;++i)
		{
			Swap(array[beg],array[i]);
			Permutation(array,beg+1,end);
			Swap(array[beg],array[i]);
		}
	}
}

