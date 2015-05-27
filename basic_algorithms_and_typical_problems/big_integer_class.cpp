#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef string::size_type Size;
typedef string::reverse_iterator r_iter;

class BigInteger {
private:
	int sign; //if the num is negative, sign == 1
	string num;
	void add(BigInteger& b);
	void sub(BigInteger& a, 
			BigInteger& b);
public:
	BigInteger(string& str);
	BigInteger& operator+(BigInteger& b);

	/*format the output according to result*/
	friend void print(const BigInteger& result){
		Size index = result.num.find_first_not_of('0');
		if(string::npos ==  index)
			cout<<'0'<<endl;
		else{
			if(result.sign){
				cout<<'-'<<result.num.substr(index)<<endl;
			}else
				cout<<result.num.substr(index)<<endl;
		}
	}
};

/*store the num except for the sign, but change the sign state*/
BigInteger::BigInteger(string& str){
	if('-' == str[0]){
		num = str.substr(1, string::npos);
		sign = 1;
	}else{
		num = str;
		sign = 0;
	}
}


void BigInteger::add(BigInteger& b){
	int aLen = num.size();
	int bLen = b.num.size();
	int maxLen = aLen > bLen? aLen : bLen;

	r_iter aIter = num.rbegin();
	r_iter bIter = b.num.rbegin();

	//two numbers' sum at most has (maxLen+1) characters
	string res(maxLen+1, '0');

	int i = maxLen;
	int carry = 0;

	for(; aIter!=num.rend() && bIter!=b.num.rend();
			++aIter, ++bIter, --i){
		int temp = *aIter - '0' + *bIter - '0' + carry;
		if(temp >=10){
			carry = 1;
			res[i] = temp % 10 + '0';
		}else{
			carry = 0;
			res[i] = temp + '0';
		}
	}

	for(; aIter != num.rend(); ++aIter, --i){
		int temp = *aIter - '0' + carry;
		if(temp >= 10){
			carry = 1;
			res[i] = temp % 10 + '0';
		}else{
			carry = 0;
			res[i] = temp + '0';
		}
	}

	for(; bIter != b.num.rend(); ++bIter, --i){
		int temp = *bIter - '0' + carry;
		if(temp >= 10){
			carry = 1;
			res[i] = temp % 10 + '0';
		}else{
			carry = 0;
			res[i] = temp + '0';
		}
	}
	//the highest character
	res[i] = carry + '0';
	num = res;
}

/*a > b*/
void BigInteger::sub(BigInteger& a, BigInteger& b) {
	Size aLen = a.num.size();
	string res(aLen, '0');
	r_iter aIter = a.num.rbegin();
	r_iter bIter = b.num.rbegin();
	int recede = 0;
	int i = aLen -1;

	for(; aIter != a.num.rend() && bIter != b.num.rend();
			++aIter, ++bIter, --i){
		int temp = *aIter - *bIter - recede;
		if(temp < 0){
			recede = 1;
			res[i] = temp + 10 +'0';
		}else{
			recede = 0;
			res[i] = temp + '0';
		}
	}

	for(; aIter != a.num.rend(); ++aIter, --i){
		int temp = *aIter - '0' - recede;
		if(temp <0){
			recede = 1;
			res[i] = temp + 10 +'0';
		}else{
			recede = 0;
			res[i] = temp + '0';
		}
	}

	num = res;	
}

/***********************************************************
 * '+' 号操作符的计算原理：                                * 
 * ----若两个数字的符号相等，则只需将两个数字直接相加即可  *
 *                                                         *
 * ----若两个数字异号，则只需用绝对值大的那个数减去绝对值  *
 *      小的那个数，最后的结果的符号取决于绝对值大的那个数 *
 *      符号                                               *
 * *********************************************************/
BigInteger& BigInteger::operator+(BigInteger& b){
	if(sign == b.sign)
		add(b);
	else{
		if(num.size()>b.num.size() || (num.size()==b.num.size() &&
					num>b.num))
				sub(*this, b);
		else{
			sub(b, *this);
			sign = b.sign;
		}
	}

	return *this;
}


int main() {

	string a, b;
	while(cin>>a>>b){
		BigInteger x(a);
		BigInteger y(b);
		BigInteger z = x + y;
		print(z);
	}

	return 0;
}

