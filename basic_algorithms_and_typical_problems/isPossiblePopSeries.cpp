/**********************************************************************
 *Given a push order of a stack, determine whether a array is possible
 *to be its corresponding pop order;
 *Input:
 * @param pPush - an array of integers, the push order
 * @param pPop - an array of integers, the pop order
 * @param nLength - the length of the push order/pop order
 * *******************************************************************/
bool isPossiblePopOrder(const int* pPush, const int* pPop, int nLength) {
	bool bPossible = false;
	if(pPop && pPush && nLength>0) {
		const int* pNextPush = pPush;
		const int* pNextPop = pPop;

		stack<int> S;
		while(pNextPop-pPop < nLength) {
			//若当前弹出序列的值不等于栈顶的值，则将压入序列中的值
			//不断压入栈中直至压入序列已经全部压入栈中
			while(S.empty() || S.top()!= *pNextPop) {
				if(!pNextPush)
					break;
				S.push(*pNextPush);
				if(pNextPush-pPush < nLength-1)
					++pNextPush;
				else
					pNextPush = NULL;
			}
			
			//输入序列压入栈中之后，如果此时栈顶的值还不是
			//对应的弹出的值，则该序列不可能是输入序列的
			//弹出序列
			if(S.top() != *pNextPop) 
				break;

			S.pop();
			++pNextPop;
		}

		if(S.empty() && pNextPop-pPop==nLength) {
			bPossible = true;
		}

		return bPossible;
	}
}
