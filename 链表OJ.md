### 删除单向链表所有的val

```c
struct ListNode* removeElements(struct ListNode* head, int val){
	if (head == NULL)
		return NULL;
	struct ListNode* prev = head;//prev用来保存找到的val，方便完成链表的重组
	struct ListNode* cur = head->next;//cur用来遍历结点
	//情况1 找到的val不是头
	while (cur != NULL){//遍历循环
		if (cur->val = val){//找到val了
			prev->next = cur->next;//保存指向要删除结点的指针
			free(cur);//删掉cur
			cur = prev->next;//cur free掉了，它要走到被删除的结点的后面
		}
		else{
			prev = cur;
			cur = cur->next;
		}
	}
	if (head->val == val){
		struct Listnode* newHead = head->next;
		free(head);
		return newHead;
	}
	else
		return head;
}
```

### 反转单链表

```c
       //NULL-->1-->2-->3-->NULL  
       //NULL<--1   2-->3-->NULL  
       //NULL<--1<--2   3-->NULL  
       //NULL<--1<--2<--3   NULL

//方式一：头删+尾插
struct ListNode* reverseList(struct ListNode* head){
	struct ListNode* ret = NULL;//ret从NULL开始往后走
	while (head != NULL){//判空链表
		struct ListNode* node = head;//node同步head，即往后遍历
		head = head->next;//设立head只是为了方便node的遍历
		node->next = ret;// 改变node结点的指针指向
		ret = node;//同步ret，ret要保持在node的前面
	}
	return ret;
}
//方式二：3指针法
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *prev, *cur, *tmp;
    prev = NULL;
    cur = head;
    if(head == NULL)
        return head;
    while(cur != 0)
    {
        tmp = cur->next;//遍历
        cur->next = prev;//cur指向前面
        prev = cur;//prev往后走  
        cur = tmp;//遍历
    }
    return prev;
}
```

### 给定一个带有头结点 head 的非空单链表，返回链表的中间结点。如果有两个中间结点，则返回第二个中间结点

```c
// f走 2 4 6 8        // 结点2个  中间2
// s走 2 3 4 5        // 结点3个  中间2
// f走 3 5 7 9        // 结点4个  中间3
//结点>2的时候:  循环开始，只要f走1下，s就跟着走1下，下来的f走与不走都不会影响中间结点；走下一个循环中间结点才会+1
struct ListNode* middleNode(struct ListNode* head){
	if (head == NULL)
	return NULL;
	struct ListNode* fast = head;
	struct ListNode* slow = head;//双指针游走，慢的走一下，快的两下
	while (1)
	{
		fast = fast->next;
		if (fast == NULL)
			break;
		slow = slow->next;
		fast = fast->next;
		if (fast == NULL)
			break;	
	}
	return slow;
}
```

###  删除链表的倒数第 *n* 个节点，并且返回链表的头结点。

```c
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* fast = fast;
    struct ListNode* slow = slow;
    fast = slow = head;//都在头
    for(int count = 0; count < n-1 ;count ++){
        fast = fast-> next;//fast领先slow  n-1下
    }
    if(fast->next == NULL){//如果n就是它的结点数
        struct ListNode* newhead = head->next;//新头变成旧头的下一个
        free(head);
        return newhead;//返回新头
    }
    else{
        struct ListNode* oldslow = slow;
        while(fast->next != NULL){
        oldslow = slow;//保存上一个slow
        fast = fast-> next;
        slow = slow->next;
        }
        oldslow->next = oldslow->next->next;
        free(slow);
        }
    return head;//返回慢的 
}
```

### 合并有序链表

```c
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if(l1==NULL)
        return l2;
    if(l2==NULL)
        return l1;
    if(l1->val < l2->val){
        l1->next = mergeTwoLists(l1->next,l2);
        return l1;
    }else{
        l2->next = mergeTwoLists(l1,l2->next);
        return l2;
    }
}
```

### 链表分割

```c
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        ListNode* slist = new ListNode (-1);
        ListNode* blist = new ListNode (-1);
        ListNode* cur = pHead, *dslist = slist , *dblist = blist;
        while(cur != NULL){
            if(cur->val < x){
                dslist->next = cur;
                dslist = cur;
}else{
                dblist->next = cur;
                    dblist = cur;
}
            cur = cur->next;
        }
        dslist->next = blist->next;
        dblist->next = 0;
        return slist->next;
    }
};
```

### 删除有序链表中重复的结点（不保留）

```c
ListNode* deleteDuplication(ListNode* pHead)//递归
	{
		if (pHead == NULL || pHead->next == NULL)//结点为0/1直接返回头
			return pHead;
		if (pHead->val == pHead->next->val)//如果当前结点是重复结点
		{
			ListNode *cur = pHead->next;//cur用来走重复节点，和上个pHead比较
			while (cur != NULL && cur->val == pHead->val)//条件含义：下个结点也是重复结点,
				cur = cur->next;//cur遍历，直到走到第一个非重复结点
			return deleteDuplication(cur);//以此达到更新pHead的目的     
            //当此时的cur已非重复结点，传给pHead,继续判断
		}
		else
		{//当前结点不是重复结点
			pHead->next = deleteDuplication(pHead->next);//pHead非重复节点，继续更新
			return pHead;//最后cur走到尾返回
		}
```

### 链表回文

```c
//1.找到中间结点 + 反转 + 两者比较   
//也可以把整个链表反转后比较
ListNode* middleNode(ListNode* head){//找中间
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
	return slow;//slow是中间结点的第一个
}
ListNode* reverseList(ListNode* head){//反转第一条
	if (head == NULL)
		return NULL;
	ListNode *cur, *prev, *next;
	prev = NULL;
	cur = head;
	next = head->next;
	while (cur != NULL){//cur是遍历
		cur->next = prev;//改变指向
		prev = cur;//更新cur
         cur = next;
		if (next != NULL)
			next = next->next;
	}
	return prev;//prev最后变成头,顺便断开两条
}
bool chkPalindrome(ListNode* A){
	ListNode * middle = middleNode(A);//middle是第一个
	ListNode * r = reverseList(middle->next);//反转后的前半条链表
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
```

### 相交链表

```c
//链表相交之方式1:时间复杂度非常高O(n^2)        双指针遍历，若链表相交，返回任一地址
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (!headA || !headB)//任一者走到最后了还没找到
			return nullptr;
		while (headA)         //headA = headA->next，A的遍历
		{
			ListNode* tmp = headB;
			if (headA == tmp)//第一个结点开始就要判断
				return headA;
			while (tmp->next != nullptr){
				tmp = tmp->next;
				if (headA == tmp)
					return headA;
			}
			headA = headA->next;
		}
		return nullptr;
	}
};
//方式2：若相交，割去长度多的那条链表，再从前往后对比指针，若指针相同就输出指针
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (!headA || !headB)
			return nullptr;
		ListNode* countA = headA;
		ListNode* countB = headB;
		int lA = 0;
		int lB = 0;
		while (countA){
			++lA;
			countA = countA->next;
		}//A 和 B 计数有多少结点
		while (countB){
			++lB;
			countB = countB->next;
		}
		int i = max(lA, lB) - min(lA, lB);//它们之间的距离
		if (lA > lB){
			for (i; i > 0; i--)
				headA = headA->next;//删1+1+1+1
		}
		else{
			for (i; i > 0; i--)
				headB = headB->next;
		}

		while (headA == headB)  {//处理结束，如果最后一个结点也不指向同一个空间，返回headA 
				headA = headA->next;//下一个是空，直接返回
				headB = headB->next;
		}
		return headA;
	}
};
```

### 判断链表是否带环

```c
/*双指针快慢遍历
设快慢指针第一次相遇时，fast走了f步，slow走了s步，
设环的长度为c，从表头到入环点需走t步，那么：
    *（1）当fast指针追上slow指针时，fast比slow多走了n个环的长度，即 f = s + n * c；
     *（2）同时，因为fast一次走2步，slow一次走1步，因此有 f = 2s；
     *    由此可得：s = n * c，f = 2 * n * c     这是相遇情况下的满足条件
     *    将slow退到起始点，fast不动，然后每人一次各走一步：
     * 当slow走到入环点时，它走了t（ = 0 * c + t ）步；而此时fast走了 2 * n * c + t 步，也到达了入环点         s-t 与 f+t  照样f是2倍速    
     * 说明他们正好相遇在了入环点。   
     */
class Solution {
public:
ListNode *detectCycle(ListNode *head) {
bool isCycle = false;//先判断是否带环，不带环直接返回NULL
ListNode* slow = head;//都从头开始走
ListNode* fast = head;
    while (fast && fast->next)
    {//找到他们相交的第一个结点
        fast = fast->next->next;
        slow = slow -> next;
        if (fast == slow){
        isCycle = true;
        break;//当相遇，要直接跳出循环
        }//fast是第一个相遇的点
    }//fast是第一个相遇的结点
    if (!isCycle)//非环
        return NULL;
    slow = head;//当他们第一次相遇的时候，把slow置于head，和fast一起往后走，此时的相遇即入口
    while (fast != slow){
        fast = fast->next;
        slow = slow->next;
    }
     return fast;
}
};
```

### 复制复杂链表

```c
//Round3：copy the next---->copy the random---->disconnect them  都需要去做一件事:cur = head
Node* copyRandomList(Node* head) {
	if (head == NULL)
		return NULL;//如果是空链表，直接返回空
	Node* cur = head;//1.copy原链表，先copy他们的结点，紧跟再原结点的后面
	while (cur != nullptr){
		Node* copy = new Node(cur->val, nullptr, nullptr);//申请新节点
		copy->next = cur->next;//copy放在结点1 2之间
		cur->next = copy;//接上去了
		cur = copy->next;//处理下个cur
	}
	cur = head;//2.copy他们的random指针
	while (cur != nullptr){
		if (cur->random != nullptr)
			cur->next->random = cur->random->next;
		cur = cur->next->next;
	}
	cur = head;//3.拆分链表
	Node *copylist = head->next;
	while (cur && cur->next){
		Node* copy = cur->next;
		cur->next = cur->next->next;
		cur = copy;
	}
	return copylist;
}
```

