#include <stdexcept>
#include <vector>
#include <iostream>

struct DoublyListNode {
	int val;
	DoublyListNode* next;
	DoublyListNode* prev;
	DoublyListNode(int val) :val(val), prev(nullptr), next(nullptr) {

	}
};

class LinkedListDeque {
private:
	DoublyListNode* front, * rear;
	int queSize = 0;
public:
	LinkedListDeque() :front(nullptr), rear(nullptr){
	}
	~LinkedListDeque() {
		DoublyListNode* pre, * cur=front;
		while (cur) {
			pre = cur;
			cur = cur->next;
			delete pre;
		}
	}
	int size() {
		return queSize;
	}
	bool isEmpty() {
		return size() == 0;
	}
	void push(int num, bool isFront) {
		DoublyListNode* node = new DoublyListNode(num);
		if (isEmpty()) {
			front = rear = node;
		}
		else if (isFront) {
			front->prev = node;
			node->next = front;
			front = node;
		}
		else {
			rear->next = node;
			node->prev = rear;
			rear = node;
		}
		queSize++;
	}
	void pushFirst(int num) {
		push(num,1);
	}
	void pushLast(int num) {
		push(num, 0);
	}
	int pop(bool isFront) {
		if (isEmpty()) {
			throw std::out_of_range("队列为空");
		}
		int val;
		if (isFront) {
			val = front->val;
			DoublyListNode* fNext = front->next;
			if (fNext != nullptr) {
				fNext->prev = nullptr;
				front->next = nullptr;
			}
			delete front;
			front = fNext;
		}
		else {
			val = rear->val;
			DoublyListNode* rPrev = rear->prev;
			if (rPrev != nullptr) {
				rPrev->next = nullptr;
				rear->prev = nullptr;
			}
			delete rear;
			rear = rPrev;
		}
		queSize--;
		return val;
	}
	int popFirst() {
		return pop(true);
	}
	int popLast() {
		return pop(false);
	}
	int peekFirst() {
		if (isEmpty()) {
			throw std::out_of_range("双向队列为空");
		}
		return front->val;
	}
	int peekLast() {
		if (isEmpty()) {
			throw std::out_of_range("双向队列为空");
		}
		return rear->val;
	}
	std::vector<int> toVector() {
		DoublyListNode* node = front;
		std::vector<int> res(size());
		for (int i = 0; i < size(); i++) {
			res[i] = node->val;
			node = node->next;
		}
		return res;
	}
};

using std::vector;
class ArrayDeque {
private:
	vector<int> nums;
	int front;
	int queSize;
public:
	ArrayDeque(int capacity) {
		nums.resize(capacity);
		front = queSize = 0;
	}
	int capacity() {
		return nums.size();
	}
	int size() {
		return queSize;
	}
	bool isEmpty() {
		return queSize == 0;
	}
	int index(int i) {
		return (i + capacity()) % capacity();
	}
	void pushFirst(int num) {
		if (queSize == capacity() ){
			std::cout << "双向队列已满" << std::endl;
			return ;
		}
		front = index(front-1);
		nums[front] = num;
		queSize++;
	}
	void pushLast(int num) {
		if (queSize == capacity()) {
			std::cout << "双向队列已满" << std::endl;
			return;
		}
		int rear = index(front + queSize);
		nums[rear] = num;
		queSize++;
	}
	int popFirst() {
		int num = peekFirst();
		front = index(front + 1);
		queSize++;
		return num;
	}
	int popLast() {
		int num = peekLast();
		queSize--;
		return num;
	}
	int peekFirst() {
		if (isEmpty()) {
			throw std::out_of_range("双向队列为空");
		}
		return nums[front];
	}
	int peekLast() {
		if (isEmpty()) {
			throw std::out_of_range("双向队列为空");
		}
		int last = index(front + queSize - 1);
		return nums[last];
	}
	vector<int> toVector() {
		vector<int> res(queSize);
		for (int i = 0, j = front; i < queSize; i++, j++) {
			res[i] = nums[index(j)];
		}
		return res;
	}
};