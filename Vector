#include<iostream>
#include<string>
using namespace std;

template <typename T>
class Vector {
private:
	const int DEFAULT_CAPACITY = 5;
	int size;
	int capacity;
	T* data;
public:
	Vector() {
		this->capacity = this->DEFAULT_CAPACITY;
		this->data = new T[capacity];
	}

	Vector(const Vector<T>& v) {
		this->size = v.size;
		this->capacity = v.capacity;
		this->data = new T[this->capacity];
		
		for (int i = 0; i < this->size; i++) {
			this->data[i] = v.data[i];
		}
	}

	~Vector() {
		delete[] data;
	}

	void resize() {
		T* newData = new T[this->capacity * 2];
		for (int i = 0; i < this->capacity; i++) {
			newData[i] = this->data[i];
		}
		this->capacity = this->capacity * 2;
		this->data = newData;
	}

	void add(T data) {
		if (this->size == this->capacity) {
			cout << "size : " << size << " capacity : " << this->capacity << " so capacity will be resize." << '\n';
			this->resize();
		}
		this->data[this->size++] = data;
	}

	void remove() {
		if (this->size == 1) {
			cout << "No data to remove." << '\n';
			return;
		}
		this->data[--this->size] = 0;
	}

	int getSize() {
		return this->size;
	}

	int getCapacity() {
		return this->capacity;
	}

	void clear() {
		for (int i = 0; i < this->size; i++) {
			this->data[i] = 0;
		}
		this->size = 0;
	}

	void print() {
		for (int i = 0; i < this->size; i++) {
			cout << "[" << i << "] : " << this->data[i] << '\n';
		}
	}

	T& operator[](const int& idx) {
		if (idx >= size) throw idx;
		return data[idx];
	}

};

int main() {
	Vector<int> vec;
	vec.add(1);
	vec.add(2);
	vec.print();

	vec.remove();
	vec.print();
	
	cout << "capacity : " << vec.getCapacity() << '\n';
	cout << "size : " << vec.getSize() << '\n';
	
	for (int i = 1; i <= 10; i++) {
		vec.add(i);
	}
	vec.print();

	cout << "capacity : " << vec.getCapacity() << '\n';
	cout << "size : " << vec.getSize() << '\n';

	vec.clear();

	vec.print();

	cout << "capacity : " << vec.getCapacity() << '\n';
	cout << "size : " << vec.getSize() << '\n';

	Vector<string> vec2;
	vec2.add("Hello");
	vec2.add("World");
	vec2.print();

	Vector<string> vec3 = vec2;
	vec3.print();

	cout << vec3[0] << '\n';
	/* The code below gives an error. */
	cout << vec3[2] << '\n';

	return 0;
}
