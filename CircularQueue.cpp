#include<iostream>
using namespace std;

template <class T>
class CircularQueue {
private:
	int front;
	int back;
	T* data;
	const int MAX_SIZE = 5;
public:
	CircularQueue<T>() {
		front = back = 0;
		data = new T[MAX_SIZE];
	}

	~CircularQueue<T>() {
		delete[] data;
	}

	void push(T value) {
		if (full()) {
			cout << "Queue is full." << '\n';
			return;
		}
		back = (back + 1) % MAX_SIZE;
		data[back] = value;
	}

	T pop() {
		if (empty()) throw - 1;
		front = (front + 1) % MAX_SIZE;
		return data[front];
	}

	bool empty() {
		return front == back;
	}

	bool full() {
		return (back + 1) % MAX_SIZE == front;
	}

};

int main() {

	CircularQueue<int> q;

	q.push(1);
	q.push(2);
	q.push(3);

	cout << q.pop() << '\n';
	cout << q.pop() << '\n';

	for (int i = 4; i <= 10 && !q.full(); i++) {
		q.push(i);
	}

	while (!q.empty()) {
		int k = q.pop();
		cout << k << '\n';
	}

	for (int i = 1; i <= 10 && !q.full(); i++) {
		q.push(i);
	}

	while (!q.empty()) {
		int k = q.pop();
		cout << k << '\n';
	}

	return 0;
}
