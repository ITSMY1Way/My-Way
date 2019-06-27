//ɾ���ظ���� ������

using namespace std;
//struct ListNode{
//	int val;//��ǰ����ֵ
//	struct ListNode *next;//�¸����
//	ListNode(int x) :
//		val(x), next(NULL) {}
//};
//class Solution {//�ݹ�
//public:
//	ListNode* deleteDuplication(ListNode* pHead)
//	{
//		if (pHead == NULL || pHead->next == NULL)//���Ϊ0/1ֱ�ӷ���ͷ
//			return pHead;
//		if (pHead->val == pHead->next->val)//�����ǰ������ظ����
//		{
//			ListNode *cur = pHead->next;//cur�������ظ��ڵ㣬���ϸ�pHead�Ƚ�
//			while (cur != NULL && cur->val == pHead->val)//�������壺�¸����Ҳ���ظ����,
//				cur = cur->next;//cur������ֱ���ߵ���һ�����ظ����
//			return deleteDuplication(cur);//�Դ˴ﵽ����pHead��Ŀ��     ����ʱ��cur�ѷ��ظ���㣬����pHead,�����ж�
//		}
//		else
//		{//��ǰ��㲻���ظ����
//			pHead->next = deleteDuplication(pHead->next);//pHead���ظ��ڵ㣬��������
//			return pHead;//���cur�ߵ�β����
//		}
//	}
//};
�������
//1.�ҵ��м��� + ��ת + ���߱Ƚ�
ListNode* middleNode(ListNode* head){//���м�
	if (head == NULL)
		return NULL;
	ListNode* slow = slow;
	ListNode* fast = fast;
	while (1)
	{
		fast = fast->next;//2 4 6
		if (fast == NULL){
			break;
		}
		slow = slow->next;//2 3 4
		fast = fast->next;//3 5 7
		if (fast == NULL){
			break;
		}
	}
	return slow;//slow���м���ĵ�һ��
}
ListNode* reverseList(ListNode* head){//��ת��һ��
	if (head == NULL)
		return NULL;
	ListNode *cur, *prev, *next;
	prev = NULL;
	cur = head;
	next = head->next;
	while (cur != NULL){//cur�Ǳ���
		cur->next = prev;//�ı�ָ��
		prev = cur;//����cur
		cur = next;

		if (next != NULL)
			next = next->next;
	}
	return prev;//prev�����ͷ,˳��Ͽ�����
}
bool chkPalindrome(ListNode* A){
	ListNode * middle = middleNode(A);//middle�ǵ�һ��
	ListNode * r = reverseList(middle->next);//��ת���ǰ��������
	ListNode *n1 = A,   *n2 = r;
	while (n1 != NULL && n2 != NULL){
		if (n1->val != n2->val){
			return false;
		}
		n1 = n1->next;
		n2 = n2->next;
	}
	return true;
}
