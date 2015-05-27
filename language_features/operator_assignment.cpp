/*the sample codes to overload the '=' operator */
class MyString {
public:
	MyString(char* m_Pdata = NULL);
	MyString(const MyString& str);
	MyString& operator=(const MyString& str);
private:
	char* m_Pdata;
};
/*************************************************
 * 这段代码有以下好处：                         **
 *--避免了对象自己给自己赋值                    **
 *--避免了内存申请失败而原来的内存已经释放的异常**
 *************************************************/
MyString& MyString::operator=(const MyString& str){
	if(this != &str){
		MyString temp(str);
		char* p = temp.m_Pdata;
		temp.m_Pdata = m_Pdata;
		m_Pdata = p;
	}

	return *this;
}
