////�����ཻ ֮��ʽ1:ʱ�临�Ӷȷǳ���O(n^2)  ˫ָ��������������ཻ��������һ��ַ
//class Solution {
//public:
//	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//		if (!headA || !headB)//��һ���ߵ�����˻�û�ҵ�
//			return nullptr;
//		while (headA)         //headA = headA->next��A�ı���
//		{
//			ListNode* tmp = headB;
//			if (headA == tmp)//��һ����㿪ʼ��Ҫ�ж�
//				return headA;
//			while (tmp->next != nullptr){
//				tmp = tmp->next;
//				if (headA == tmp)
//					return headA;
//			}
//			headA = headA->next;
//		}
//		return nullptr;
//	}
//};
//
////��ʽ2�����ཻ����ȥ���ȶ�����������ٴ�ǰ����Ա�ָ�룬��ָ����ͬ�����ָ��
//class Solution {
//public:
//	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//		if (!headA || !headB)
//			return nullptr;
//		ListNode* countA = headA;
//		ListNode* countB = headB;
//		int lA = 0;
//		int lB = 0;
//		while (countA){
//			++lA;
//			countA = countA->next;
//		}//A �� B �����ж��ٽ��
//		while (countB){
//			++lB;
//			countB = countB->next;
//		}
//		int i = max(lA, lB) - min(lA, lB);//����֮��ľ���
//		if (lA > lB){
//			for (i; i > 0; i--)
//				headA = headA->next;//ɾ1+1+1+1
//		}
//		else{
//			for (i; i > 0; i--)
//				headB = headB->next;
//		}
//
//		while (headA == headB)  {//���������������һ�����Ҳ��ָ��ͬһ���ռ䣬����headA 
//				headA = headA->next;//��һ���ǿգ�ֱ�ӷ���
//				headB = headB->next;
//		}
//		return headA;
//	}
//};
////�ж������Ƿ����  ˫ָ�������������ָ����ͬ����������
////˫ָ���������
//class Solution {
//public:
//	bool hasCycle(ListNode *head) {
//		ListNode* slow = head;//����ͷ��ʼ��
//		ListNode* fast = head;
//		while (fast != nullptr && fast->next != nullptr){
//			fast = fast->next->next;//һ���������������ߵ���ֱ�ӷ���false
//			slow = slow->next;
//			if (fast == slow)//����������
//				return true;
//		}
//		return false;
//	}
//};
////��������ĵ�һ�����
///*˫ָ���������
//�����ָ���һ������ʱ��fast����f����slow����s����
//�軷�ĳ���Ϊc���ӱ�ͷ���뻷������t������ô��
//*��1����fastָ��׷��slowָ��ʱ��fast��slow������n�����ĳ��ȣ��� f = s + n * c��
//*��2��ͬʱ����Ϊfastһ����2����slowһ����1��������� f = 2s��
//*    �ɴ˿ɵã�s = n * c��f = 2 * n * c     ������������µ���������
//*    ��slow�˵���ʼ�㣬fast������Ȼ��ÿ��һ�θ���һ����
//* ��slow�ߵ��뻷��ʱ��������t�� = 0 * c + t ����������ʱfast���� 2 * n * c + t ����Ҳ�������뻷��         s-t �� f+t  ����f��2����
//* ˵�������������������뻷�㡣
//*/
//class Solution {
//public:
//	ListNode *detectCycle(ListNode *head) {
//		bool isCycle = false;//���ж��Ƿ������������ֱ�ӷ���NULL
//		ListNode* slow = head;//����ͷ��ʼ��
//		ListNode* fast = head;
//		while (fast && fast->next)
//		{//�ҵ������ཻ�ĵ�һ�����
//			fast = fast->next->next;
//			slow = slow->next;
//			if (fast == slow){
//				isCycle = true;
//				break;//��������Ҫֱ������ѭ��
//			}//fast�ǵ�һ�������ĵ�
//		}//fast�ǵ�һ�������Ľ��
//		if (!isCycle)//�ǻ�
//			return NULL;
//		slow = head;//�����ǵ�һ��������ʱ�򣬰�slow����head����fastһ�������ߣ���ʱ�����������
//		while (fast != slow){
//			fast = fast->next;
//			slow = slow->next;
//		}
//		return fast;
//	}
//};

//���Ƹ�������

class Node {
public:int val;Node* next;Node* random;
Node() {}
Node(int _val, Node* _next, Node* _random) {val = _val;next = _next;random = _random;
}
};
//Round3��copy the next---->copy the random---->disconnect them  ����Ҫȥ��һ����:cur = head
Node* copyRandomList(Node* head) {
	if (head == NULL)
		return NULL;//����ǿ�����ֱ�ӷ��ؿ�
	Node* cur = head;//1.copyԭ������copy���ǵĽ�㣬������ԭ���ĺ���
	while (cur != nullptr){
		Node* copy = new Node(cur->val, nullptr, nullptr);//�����½ڵ�
		copy->next = cur->next;//copy���ڽ��1 2֮��
		cur->next = copy;//����ȥ��
		cur = copy->next;//�����¸�cur
	}
	cur = head;//2.copy���ǵ�randomָ��
	while (cur != nullptr){
		if (cur->random != nullptr)
			cur->next->random = cur->random->next;
		cur = cur->next->next;
	}
	cur = head;//3.�������
	Node *copylist = head->next;
	while (cur && cur->next){
		Node* copy = cur->next;
		cur->next = cur->next->next;
		cur = copy;
	}
	return copylist;
}