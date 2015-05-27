/*reverse a list*/
struct ListNode {
	int val;
	struct ListNode* next;
};

typedef ListNode* List;

List reverse_list(List head) {
	List newHead = NULL; //作为新的链表头，在遍历的过程中保存
								//前一个链表节点
	while(head) {
		List next = head->next;
		head->next = newHead;
		newHead = head;
		head = next;
	}

	return newHead;
}

