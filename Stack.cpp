#include<iostream>
#include<string>
using namespace std;

template <class T>
class Stack {
private:
	int capacity;
	int top;
	T* data;
public:
	Stack<T>() {
		this->top = 0;
		this->capacity = 10;
		data = new T[this->capacity];
	}
	~Stack<T>() {
		delete[] data;
	}
	void resize() {
		T* newData = new T[this->capacity * 2];
		for (int i = 0; i < this->capacity; i++) {
			newData[i] = this->data[i];
		}

		delete this->data;

		this->capacity = this->capacity * 2;
		this->data = newData;
	}

	void push(T data) {
		if (this->top == this->capacity) {
			this->resize();
		}
		this->data[this->top] = data;
		this->top++;
	}

	void pop() {
		if (top == 0) throw -1;
		this->data[--this->top] = 0;
	}

	int getTop() {
		if (this->top == 0) throw - 1;
		return this->data[this->top - 1];
	}

	int getSize() {
		return this->top;
	}

	bool empty() {
		return !this->top > 0;
	}
};

int main() {
	Stack<int> stack;
	stack.push(1);
	stack.push(2);

	cout << stack.getTop() << '\n'; // 2
	stack.pop();
	cout << stack.getTop() << '\n'; // 1
	
	stack.push(2);
	stack.push(1);
	stack.push(3);
	cout << stack.getTop() << '\n'; // 3
	cout << stack.getSize() << '\n'; // 4

	while (!stack.empty()) {
		int k = stack.getTop();
		cout << k << '\n';
		stack.pop();
	}

	cout << stack.getSize() << '\n'; // 0

	for (int i = 1; i <= 100; i++) {
		stack.push(i);
	}

	cout << stack.getSize() << '\n'; // 100

	while (!stack.empty()) {
		int k = stack.getTop();
		cout << k << '\n';
		stack.pop();
	}

	cout << stack.getSize() << '\n'; // 0

	return 0;
}
