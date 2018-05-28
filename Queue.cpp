#include<iostream>
using namespace std;

template <class T>
class Queue {
private:
	int front;
	int back;
	T* data;
	int capacity;
public:
	Queue<T>() {
		capacity = 5;
		data = new T[capacity];
	}
	
	~Queue<T>() {
		delete[] data;
	}
	
	void resize() {
		T* newData = new T[capacity * 2];
		for (int i = front; i <= back; i++) {
			newData[i] = data[i];
		}
		
		delete[] data;

		capacity = capacity * 2;
		data = newData;
	}

	void push(T value) {
		if (back == capacity) {
			resize();
		}
		data[back++] = value;
	}

	T getFront() {
		if (empty()) throw - 1;
		return data[front];
	}

	void pop() {
		if (empty()) throw - 1;
		data[front] = -1;
		front++;
	}

	bool empty() {
		return back == front;
	}

	int size() {
		return back - front;
	}
};

int main() {

	Queue<int> q;

	cout << "Q size : " << q.size() << '\n';

	q.push(1);
	q.push(2);
	q.push(3);

	cout << "Q size : " << q.size() << '\n';

	cout << q.getFront() << '\n';
	q.pop();

	cout << q.getFront() << '\n';
	q.pop();

	cout << "Q size : " << q.size() << '\n';

	for (int i = 4; i <= 10; i++) {
		q.push(i);
	}

	cout << "Q size : " << q.size() << '\n';

	while (!q.empty()) {
		int k = q.getFront();
		q.pop();
		cout << k << '\n';
	}
	
	cout << "Q size : " << q.size() << '\n';

	q.pop(); // error.

	return 0;
} 
