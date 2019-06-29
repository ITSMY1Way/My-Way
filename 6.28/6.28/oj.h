
// ¸´ÔÓÁ´±í¸´ÖÆ
struct RandomListNode *copyRandomList(struct RandomListNode *head) {
	if (head == NULL) {
		return NULL;
	}

	struct RandomListNode *cur = head;
	while (cur != NULL) {
		RandomListNode *node = (RandomListNode *)malloc(sizeof(RandomListNode));
		node->label = cur->label;
		node->random = NULL;

		RandomListNode *next = cur->next;
		cur->next = node;
		node->next = next;

		cur = next;
	}

	// ¸´ÖÆ random
	cur = head;
	while (cur != NULL) {
		RandomListNode *node = cur->next;
		if (cur->random != NULL) {
			node->random = cur->random->next;
		}

		cur = node->next;
	}

	cur = head;
	RandomListNode *ret = head->next;
	while (cur != NULL) {
		RandomListNode *node = cur->next;
		cur->next = node->next;
		if (node->next != NULL) {
			node->next = cur->next->next;
		}

		cur = cur->next;
	}

	return ret;
}