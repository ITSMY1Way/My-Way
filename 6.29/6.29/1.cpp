////using namespace std;
//////栈 后进先出 数组实现
//////typedef struct Stack {
//////	int array[100];
//////	int top;
//////}	Stack;
//////
//////// 初始化
//////void StackInit(Stack *stack) {
//////	stack->top = 0;
//////}
//////
//////// 压栈（尾插）
//////void StackPush(Stack *stack, int value) {
//////	stack->array[stack->top] = value;
//////	stack->top++;
//////}
//////// 出栈、弹出（尾删）
//////void StackPop(Stack *stack) {
//////	stack->top--;
//////}
//////
//////// 返回栈顶元素
//////int StackTop(const Stack *stack) {
//////	return stack->array[stack->top - 1];
//////}
//////
//////// 判断是否为空
//////int StackEmpty(const Stack *stack) {
//////	return stack->top == 0 ? 1 : 0;
//////}
//////
//////// 获取 size
//////int StackSize(const Stack *stack) {
//////	return stack->top;
//////}
//////
//////
//////
//////
//////// 1. 括号匹配
////////利用栈的结构进行判断，左括号全部进栈，然后遇到有括号的时候进行弹栈，还要处理特殊情况
//////class Solution {
//////public:
//////	bool isValid(string s) {
//////		stack<char> sta;
//////		int i = 0; n = s.size;
//////		while (i < n){//判断是不是左括号
//////			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
//////				sta.push(s[i]);//入栈
//////			else{
//////				if (sta.empty())
//////					return false;
//////				char tmp = sta.top();//要出栈
//////				if (s[i] == ')' && tmp != '(') return false;
//////				if (s[i] == ']' && tmp != '[') return false;
//////				if (s[i] == '}' && tmp != '{') return false;//括号不匹配的情况
//////				sta.pop();//匹配的时候直接弹栈
//////			}
//////			i++;//一次循环结束
//////		}
//////		return sta.empty() ? true : false;//到最后如果匹配栈肯定为空，返回true
//////	}
//////};
//////Queue 队列  先进先出 链表实现
//////typedef struct Node {
//////	int value;
//////	struct Node *next;
//////}	Node;
//////
//////// 头删 + 尾插
//////typedef struct Queue {
//////	Node *front;		// 链表的第一个结点
//////	Node *rear;			// 链表的最后一个结点
//////	int size;			// 数据个数
//////}	Queue;
//////
//////// 初始化
//////void QueueInit(Queue *queue) {
//////	queue->front = NULL;
//////	queue->rear = NULL;
//////	queue->size = 0;
//////}
//////// 销毁
//////void QueueDestroy(Queue *queue) {
//////	Node *node, *next;
//////	for (node = queue->front; node != NULL; node = next){
//////		next = node->next;
//////		free(node);
//////	}
//////	queue->front = queue->rear = NULL;
//////	queue->size = 0;
//////}
//////// Push ，队尾插入，即链表的尾插
//////void QueuePush(Queue *queue, int val) {
//////	Node* node = (Node *)malloc(sizeof(Node));
//////	node->value = val;
//////	node->next = NULL;
//////	queue->size++;
//////	if (queue->rear != NULL){
//////		queue->rear->next = node;
//////		queue->rear = node;
//////	}
//////	else//空队列
//////		queue->front = queue->rear = node;
//////}
//////
//////// Pop， 队首出列，即链表的头删
//////void QueuePop(Queue *queue) {
//////	assert(queue->size > 0);
//////	queue->size--;
//////	Node* front = queue->front;
//////	queue->front = queue->front->next;
//////	free(front);
//////	if (queue->front == NULL)//只有一个结点的情况
//////		queue->rear = NULL;
//////}
//////// Front	返回队首元素
//////int QueueFront(const Queue *queue) {
//////	return queue->front->value;
//////}
//////// Rear		返回队尾元素
//////int QueueRear(const Queue *queue) {
//////	return queue->rear->value;
//////}
//////// Empty	是否为空
//////int QueueEmpty(const Queue *queue) {
//////	return queue->size == 0? 1: 0
//////}
//////// Size
//////int QueueEmpty(const Queue *queue) {
//////	return queue->size;
//////}
//////队列实现栈  后进后出 ==》 后进先出
//////class MyStack {
//////	queue<int> nums;
//////public:
//////	MyStack() {
//////	}
//////	void push(int x) {//入栈，尾插
//////		nums.push(x);//x要入栈，x先出
//////		//将前面的size-1个元素放到后面去
//////		for (int i = 0; i < nums.size() - 1; i++){
//////			nums.push(nums.front());//把第一个元素尾插
//////			nums.pop();//头删  插完了删去它     即完成了它的置后
//////		}
//////	}
//////	int pop() {//出栈，头删
//////		int num = nums.front();//给头
//////		nums.pop();
//////		return num;
//////	}
//////	int top() {//获得栈顶元素
//////		return nums.front();
//////	}
//////	bool empty() {
//////		return nums.empty();
//////	}
//////};
//////用栈实现队列 后进先出 ==》 后进后出    
//////双栈实现,可以通过b栈把a栈的数据倒置，此时栈的top=队列的peak，可实现peak和pop，操作完把b转回a
////class MyQueue {
////public:
////	stack<int> a;
////	stack<int> b;
////	MyQueue() {
////	}
////	void push(int x) {//入队，尾插
////		a.push(x);
////	}
////	int pop() {//出队，头删
////		int len;
////		len = a.size();
////		for (int i = 0; i < len; ++i){
////			b.push(a.top());//倒置,把a栈的栈顶元素插到b栈的栈底
////			a.pop();//a栈出栈，更新栈顶，处理下个元素
////		}
////		int cur;//这里不能写成一条语句，下面的peek函数还要用cur；
////		cur = b.top();//保存要删的头，
////		b.pop();//操作结束，现在要还原a栈
////		for (int j = 0; j < len - 1; ++j){//j-1是因为原先的栈尾已经删去了
////			a.push(b.top());
////			b.pop();
////		}
////		return cur;
////	}
////	int peek() {//返回队首元素
////		int len;
////		len = a.size();
////		for (int i = 0; i < len; ++i){
////			b.push(a.top());
////			a.pop();
////		}
////		int cur;
////		cur = b.top();
////		for (int j = 0; j < len; ++j){
////			a.push(b.top());
////			b.pop();
////		}
////		return cur;
////	}
////	bool empty() {//是否为空
////		return a.empty() && b.empty();
////	}
////};
////最小栈 
////最小栈 
//public:
//	stack <int> left; //存正常数据
//	stack <int> right;//存当前最小数据
//	MinStack() {
//	}
//	void push(int x) {//入栈 尾插
//		left.push(x);//所有元素都回入left
//		if (right.empty() || x <= right.top()) {//把第一个x压2次（如果只有一个元素就压唯一的x一次）
//			right.push(x);//如果right的栈底已经不是最小了，尾插新的x
//		}
//	}
//	void pop() {//出栈，头删
//		if (left.top() == right.top())
//			right.pop();//如果left的栈顶top刚好是最小的，那right也要删去
//		left.pop();
//	}
//	int top() {//返回栈顶元素
//		return left.top();
//	}
//	int getMin() {//最小数据
//		return right.top();
//	}
//
//public:
//	stack<int> s;
//	MinStack() {
//	}
//void push(int x) {//入栈，尾插
//	if (s.empty()){
//		s.push(x);
//		s.push(x);
//	}else{
//		int tmp = s.top();//要保存上一个当前的最大值和当前的x比较
//		s.push(x);//下面存的是当前数据
//		if (x < tmp)
//			s.push(x);
//		else
//			s.push(tmp);
//	}
//}
//void pop() {//出栈，头删
//	s.pop();
//	s.pop();
//}
//int top() {//返回栈顶元素
//	int tmp = s.top();//保存最小值
//	s.pop();//删去它，才能去访问下一个，也就是栈顶元素
//	int top = s.top;
//	s.push(tmp);
//	return top;
//}
//int getMin() {
//	return s.top();
//}
//环形队列
class MyCircularQueue {
public:
	int *array;
	int capacity;
	int size;
	int front;
	int rear;
	MyCircularQueue(int k) {
		array = (int *)malloc(sizeof(int)* k);
		capacity = k;
		size = 0;
		front = 0;
		rear = 0;
	}


	bool enQueue(int value) {
		if (size == capacity) {
			return false;
		}
		array[rear] = value;
		rear = (rear + 1) % capacity;
		size++;

		return true;
	}
	bool deQueue() {
		if (size == 0) {
			return false;
		}

		front = (front + 1) % capacity;
		size--;
		return true;
	}
	int Front() {
		if (size == 0) {
			return -1;
		}
		return array[front];
	}
	int Rear() {
		if (size == 0) {
			return -1;
		}
		return array[(rear + capacity - 1) % capacity];
	}
	bool isEmpty() {
		return size == 0;
	}
	bool isFull() {
		return size == capacity;
	}
};