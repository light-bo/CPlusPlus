/**********************************************
 * 判断一个链表是否存在环，方法是利用两根指针 *
 *	，其中一根走得快一点，另一根则走得慢一点   *
 *	若两根指针“相遇”了，则说明链表存在环，否则 *
 *	则说明链表不存在环！
 *	*******************************************/
bool judge_list_have_loop(List* list) {
	List* low, *fast;
	low = list;
	fast = list->next;

	while(fast!=NULL && fast->next!=NULL) {
		low = low->next;
		fast = fast->next->next;
		if(low == fast)
			return true;
	}

	return false;
}





