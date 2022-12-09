/* 641. Design Circular Deque */

/*
Design your implementation of the circular double-ended queue (deque).

Implement the MyCircularDeque class:

MyCircularDeque(int k) Initializes the deque with a maximum size of k.
boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
boolean isEmpty() Returns true if the deque is empty, or false otherwise.
boolean isFull() Returns true if the deque is full, or false otherwise.

Example 1:

Input
["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 2, true, true, true, 4]

Explanation
mycirculardeque mycirculardeque = new mycirculardeque(3);
mycirculardeque.insertlast(1);  // return true
mycirculardeque.insertlast(2);  // return true
mycirculardeque.insertfront(3); // return true
mycirculardeque.insertfront(4); // return false, the queue is full.
mycirculardeque.getrear();      // return 2
mycirculardeque.isfull();       // return true
mycirculardeque.deletelast();   // return true
mycirculardeque.insertfront(4); // return true
mycirculardeque.getfront();     // return 4

Constraints:

1 <= k <= 1000
0 <= value <= 1000
At most 2000 calls will be made to insertFront, insertLast, deleteFront, deleteLast, getFront, getRear, isEmpty, isFull.
*/

#include <iostream>
#include <vector>

using namespace std;

class MyCircularDeque {
private:
	int front;
	int rear;
	int capacity;
	vector<int> elements;

public:
	MyCircularDeque(int k) {
		capacity = k+1;
		elements = vector<int>(capacity);
		front = rear = 0;
	}
	
	bool insertFront(int value) {
		if (isFull()) {
			return false;
		}
		front = (front - 1 + capacity) % capacity;
		elements[front] = value;
		return true;
	}
	
	bool insertLast(int value) {
		if (isFull()) {
			return false;
		}
		elements[rear] = value;
		rear = (rear + 1) % capacity;
		return true;
	}
	
	bool deleteFront() {
		if (isEmpty()) {
			return false;
		}
		front = (front + 1) % capacity;
		return true;
	}
	
	bool deleteLast() {
		if (isEmpty()) {
			return false;
		}
		rear = (rear - 1 + capacity) % capacity;
		return true;
	}
	
	int getFront() {
		if (isEmpty()) {
			return -1;
		}
		return elements[front];
	}
	
	int getRear() {
		if (isEmpty()) {
			return -1;
		}
		return elements[((rear - 1 + capacity) % capacity)];
	}
	
	bool isEmpty() {
		return rear == front;
	}
	
	bool isFull() {
		return ((rear + 1) % capacity) == front;
	}
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

int main()
{
	cout << "Hello! leetcode 641\n";

	MyCircularDeque* obj = new MyCircularDeque(3);

	bool param_1 =obj->insertLast(1);  // return true
	bool param_2 =obj->insertLast(2);  // return true
	bool param_3 =obj->insertFront(3); // return true
	bool param_4 =obj->insertFront(4); // return false, the queue is full.
	int  param_5 =obj->getRear();      // return 2
	int  param_6 =obj->isFull();       // return true
	bool param_7 =obj->deleteLast();   // return true
	bool param_8 =obj->insertFront(4); // return true
	int  param_9 =obj->getFront();     // return 4

	cout << param_1 << ' ';
	cout << param_2 << ' ';
	cout << param_3 << ' ';
	cout << param_4 << ' ';
	cout << param_5 << ' ';
	cout << param_6 << ' ';
	cout << param_7 << ' ';
	cout << param_8 << ' ';
	cout << param_9 << ' ';
	cout << endl;
}