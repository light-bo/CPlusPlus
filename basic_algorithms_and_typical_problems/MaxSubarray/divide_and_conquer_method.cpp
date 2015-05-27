//求解一个数组的最大子数组（元素和为最大），采用的方法是“分治法”
//本算法将数组分为三部分：
//    数组的左半部分
//    数组的右半部分
//    横跨左半部分和右半部分的部分
//
#include <iostream>
using namespace std;

//该类的对象用于存储算法返回的结果
class Result{
public:
	int low;
	int high;
	int max_sum;
	Result():low(-1), high(-1), max_sum(0x80000000){}
	Result(int low, int high, int max_sum){
		this->low = low;
		this->high = high;
		this->max_sum = max_sum;
	}
};

//找出横跨中间位置的子数组的最大子数组
Result find_cross_subarray
(
 int* array, int low,
 int mid, int  high
)
{
	int left_sum = 0;
	int left_max = 0x80000000;
	int left_index, right_index;

	for(int i=mid;i>=low;--i){
		left_sum += array[i];
		if(left_sum > left_max){
			left_max = left_sum;
			left_index = i;
		}
	}

	int right_sum = 0;
	int right_max = 0x80000000;
	
	for(int j=mid+1;j<=high;++j){
		right_sum += array[j];
		if(right_sum > right_max){
			right_max = right_sum;
			right_index = j;
		}
	}

	Result result(left_index, right_index,
			left_max + right_max);

	return result;
}

//递归找出数组的最大子数组
Result find_max_sum_subarray(int* array, int low, int high){
	if(low == high)
		return Result(low, high, array[low]);
	int mid = low + ((high - low)>>1);
	//int mid =(low + high)/2;
	Result left, right, cross;
	left = find_max_sum_subarray(array, low, mid);
	right = find_max_sum_subarray(array, mid+1, high);
	cross = find_cross_subarray(array, low, mid, high);

	if(left.max_sum>=right.max_sum && 
			left.max_sum>=cross.max_sum)
		return left;
	else if(right.max_sum>=left.max_sum &&
			right.max_sum>=cross.max_sum)
		return right;
	else
		return cross;
}

int main(){
	int size;
	cout<<"size:";
	cin>>size;
	int* array = new int[size];
	for(int i=0;i<size;++i)
		cin>>array[i];
	
	Result result;
	result = find_max_sum_subarray(array,
			0, size-1);
	cout<<"subaray: ";
	for(int i=result.low;i<=result.high;++i)
		cout<<array[i]<<((i == result.high)?
				"\n":" ");
	cout<<"max_sum: "<<result.max_sum<<endl;

	delete []array;

	return 0;
}

