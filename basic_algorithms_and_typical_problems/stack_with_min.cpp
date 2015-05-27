/************************************************************
 * stack with min function, and the time complexity of ******
 * min function is O(1)                                ******
 * *********************************************************/

/*This method's need O(2n) space complexity*/
class StackWithMin {
private:
	stack<int> m_data;//the stack to store data
	stack<int> m_min; //the stack to store the present min number

public:
	void push(int value);
	void pop();
	int min();
};

/*each time push the smaller one between the value and 
 *m_min.top() to the m_min stack*/
void StackWithMin::push(int value) {
	m_data.push(value);
	if(0==m_min.size() || value<m_min.top())
		m_min.push(value);
	else
		m_min.push(m_min.top());
}

void StackWithMin::pop() {
	assert(m_data.size()>0 && m_min.size()>0);	
	m_data.pop();
	m_min.pop();
}

int StackWithMin::min() {
	return m_min.top();
}

/******************************************************************
 * 该方法比上面的方法在大多数的情况下比上面的方法需要更少的空间 ***
 * 主要的优化在于在进栈的时候，只将比当前的最小值更小或者是相等 ***
 * 的数进栈。                                                   ***
 * ****************************************************************/
class MinStack {
public:
    void push(int x) {
        dataStack.push(x);
        if(minStack.empty()) {
            minStack.push(x);
        } else if(x <= minStack.top())
            minStack.push(x);
    }

    void pop() {
        if(dataStack.empty())
            throw invalid_argument("invalid input!");
        if(dataStack.top() == minStack.top()) {  
            dataStack.pop();
            minStack.pop();
        } else 
            dataStack.pop();
    }

    int top() {
        if(dataStack.empty())
            throw invalid_argument("invalid input!");
            
        return dataStack.top();
    }

    int getMin() {
        if(dataStack.empty())
            throw invalid_argument("invalid input!");
        return minStack.top();
    }
private:
    stack<int> dataStack;
    stack<int> minStack;
};
