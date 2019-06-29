////using namespace std;
//////ջ ����ȳ� ����ʵ��
//////typedef struct Stack {
//////	int array[100];
//////	int top;
//////}	Stack;
//////
//////// ��ʼ��
//////void StackInit(Stack *stack) {
//////	stack->top = 0;
//////}
//////
//////// ѹջ��β�壩
//////void StackPush(Stack *stack, int value) {
//////	stack->array[stack->top] = value;
//////	stack->top++;
//////}
//////// ��ջ��������βɾ��
//////void StackPop(Stack *stack) {
//////	stack->top--;
//////}
//////
//////// ����ջ��Ԫ��
//////int StackTop(const Stack *stack) {
//////	return stack->array[stack->top - 1];
//////}
//////
//////// �ж��Ƿ�Ϊ��
//////int StackEmpty(const Stack *stack) {
//////	return stack->top == 0 ? 1 : 0;
//////}
//////
//////// ��ȡ size
//////int StackSize(const Stack *stack) {
//////	return stack->top;
//////}
//////
//////
//////
//////
//////// 1. ����ƥ��
////////����ջ�Ľṹ�����жϣ�������ȫ����ջ��Ȼ�����������ŵ�ʱ����е�ջ����Ҫ�����������
//////class Solution {
//////public:
//////	bool isValid(string s) {
//////		stack<char> sta;
//////		int i = 0; n = s.size;
//////		while (i < n){//�ж��ǲ���������
//////			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
//////				sta.push(s[i]);//��ջ
//////			else{
//////				if (sta.empty())
//////					return false;
//////				char tmp = sta.top();//Ҫ��ջ
//////				if (s[i] == ')' && tmp != '(') return false;
//////				if (s[i] == ']' && tmp != '[') return false;
//////				if (s[i] == '}' && tmp != '{') return false;//���Ų�ƥ������
//////				sta.pop();//ƥ���ʱ��ֱ�ӵ�ջ
//////			}
//////			i++;//һ��ѭ������
//////		}
//////		return sta.empty() ? true : false;//��������ƥ��ջ�϶�Ϊ�գ�����true
//////	}
//////};
//////Queue ����  �Ƚ��ȳ� ����ʵ��
//////typedef struct Node {
//////	int value;
//////	struct Node *next;
//////}	Node;
//////
//////// ͷɾ + β��
//////typedef struct Queue {
//////	Node *front;		// ����ĵ�һ�����
//////	Node *rear;			// ��������һ�����
//////	int size;			// ���ݸ���
//////}	Queue;
//////
//////// ��ʼ��
//////void QueueInit(Queue *queue) {
//////	queue->front = NULL;
//////	queue->rear = NULL;
//////	queue->size = 0;
//////}
//////// ����
//////void QueueDestroy(Queue *queue) {
//////	Node *node, *next;
//////	for (node = queue->front; node != NULL; node = next){
//////		next = node->next;
//////		free(node);
//////	}
//////	queue->front = queue->rear = NULL;
//////	queue->size = 0;
//////}
//////// Push ����β���룬�������β��
//////void QueuePush(Queue *queue, int val) {
//////	Node* node = (Node *)malloc(sizeof(Node));
//////	node->value = val;
//////	node->next = NULL;
//////	queue->size++;
//////	if (queue->rear != NULL){
//////		queue->rear->next = node;
//////		queue->rear = node;
//////	}
//////	else//�ն���
//////		queue->front = queue->rear = node;
//////}
//////
//////// Pop�� ���׳��У��������ͷɾ
//////void QueuePop(Queue *queue) {
//////	assert(queue->size > 0);
//////	queue->size--;
//////	Node* front = queue->front;
//////	queue->front = queue->front->next;
//////	free(front);
//////	if (queue->front == NULL)//ֻ��һ���������
//////		queue->rear = NULL;
//////}
//////// Front	���ض���Ԫ��
//////int QueueFront(const Queue *queue) {
//////	return queue->front->value;
//////}
//////// Rear		���ض�βԪ��
//////int QueueRear(const Queue *queue) {
//////	return queue->rear->value;
//////}
//////// Empty	�Ƿ�Ϊ��
//////int QueueEmpty(const Queue *queue) {
//////	return queue->size == 0? 1: 0
//////}
//////// Size
//////int QueueEmpty(const Queue *queue) {
//////	return queue->size;
//////}
//////����ʵ��ջ  ������ ==�� ����ȳ�
//////class MyStack {
//////	queue<int> nums;
//////public:
//////	MyStack() {
//////	}
//////	void push(int x) {//��ջ��β��
//////		nums.push(x);//xҪ��ջ��x�ȳ�
//////		//��ǰ���size-1��Ԫ�طŵ�����ȥ
//////		for (int i = 0; i < nums.size() - 1; i++){
//////			nums.push(nums.front());//�ѵ�һ��Ԫ��β��
//////			nums.pop();//ͷɾ  ������ɾȥ��     ������������ú�
//////		}
//////	}
//////	int pop() {//��ջ��ͷɾ
//////		int num = nums.front();//��ͷ
//////		nums.pop();
//////		return num;
//////	}
//////	int top() {//���ջ��Ԫ��
//////		return nums.front();
//////	}
//////	bool empty() {
//////		return nums.empty();
//////	}
//////};
//////��ջʵ�ֶ��� ����ȳ� ==�� ������    
//////˫ջʵ��,����ͨ��bջ��aջ�����ݵ��ã���ʱջ��top=���е�peak����ʵ��peak��pop���������bת��a
////class MyQueue {
////public:
////	stack<int> a;
////	stack<int> b;
////	MyQueue() {
////	}
////	void push(int x) {//��ӣ�β��
////		a.push(x);
////	}
////	int pop() {//���ӣ�ͷɾ
////		int len;
////		len = a.size();
////		for (int i = 0; i < len; ++i){
////			b.push(a.top());//����,��aջ��ջ��Ԫ�ز嵽bջ��ջ��
////			a.pop();//aջ��ջ������ջ���������¸�Ԫ��
////		}
////		int cur;//���ﲻ��д��һ����䣬�����peek������Ҫ��cur��
////		cur = b.top();//����Ҫɾ��ͷ��
////		b.pop();//��������������Ҫ��ԭaջ
////		for (int j = 0; j < len - 1; ++j){//j-1����Ϊԭ�ȵ�ջβ�Ѿ�ɾȥ��
////			a.push(b.top());
////			b.pop();
////		}
////		return cur;
////	}
////	int peek() {//���ض���Ԫ��
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
////	bool empty() {//�Ƿ�Ϊ��
////		return a.empty() && b.empty();
////	}
////};
////��Сջ 
////��Сջ 
//public:
//	stack <int> left; //����������
//	stack <int> right;//�浱ǰ��С����
//	MinStack() {
//	}
//	void push(int x) {//��ջ β��
//		left.push(x);//����Ԫ�ض�����left
//		if (right.empty() || x <= right.top()) {//�ѵ�һ��xѹ2�Σ����ֻ��һ��Ԫ�ؾ�ѹΨһ��xһ�Σ�
//			right.push(x);//���right��ջ���Ѿ�������С�ˣ�β���µ�x
//		}
//	}
//	void pop() {//��ջ��ͷɾ
//		if (left.top() == right.top())
//			right.pop();//���left��ջ��top�պ�����С�ģ���rightҲҪɾȥ
//		left.pop();
//	}
//	int top() {//����ջ��Ԫ��
//		return left.top();
//	}
//	int getMin() {//��С����
//		return right.top();
//	}
//
//public:
//	stack<int> s;
//	MinStack() {
//	}
//void push(int x) {//��ջ��β��
//	if (s.empty()){
//		s.push(x);
//		s.push(x);
//	}else{
//		int tmp = s.top();//Ҫ������һ����ǰ�����ֵ�͵�ǰ��x�Ƚ�
//		s.push(x);//�������ǵ�ǰ����
//		if (x < tmp)
//			s.push(x);
//		else
//			s.push(tmp);
//	}
//}
//void pop() {//��ջ��ͷɾ
//	s.pop();
//	s.pop();
//}
//int top() {//����ջ��Ԫ��
//	int tmp = s.top();//������Сֵ
//	s.pop();//ɾȥ��������ȥ������һ����Ҳ����ջ��Ԫ��
//	int top = s.top;
//	s.push(tmp);
//	return top;
//}
//int getMin() {
//	return s.top();
//}
//���ζ���
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