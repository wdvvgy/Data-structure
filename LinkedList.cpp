#include<iostream>
#include<string>
using namespace std;

template <typename T>
class Node {
private:
	Node<T>* next;
	Node<T>* pre;
	T data;
public:
	Node(T data) : data(data) {
		
	}
	~Node() {
		cout << data << " is deleted." << '\n';

	}

	Node<T>* getNext() {
		return next;
	}

	bool addNode(T data) {
		if (this->next != nullptr) return this->next->addNode(data);
		Node<T>* newNode = new Node<T>(data);
		this->next = newNode;
		newNode->pre = this;
		cout << "data (" << data << ") is added." << '\n';
		return true;
	}

	bool addNodeAfterNode(T data, T afterTarget) {
		if (this->data == afterTarget) {
			Node<T>* newNode = new Node<T>(data);
			
			Node<T>* tmpNext = this->next;
			newNode->next = tmpNext;

			if(tmpNext != nullptr) tmpNext->pre = newNode;
			newNode->pre = this;
			
			this->next = newNode;

			cout << "data (" << data << ") is added after (" << afterTarget << ")\n";

			return true;
		}
		if (this->next == nullptr) {
			cout << "afterTarget (" << afterTarget << ") is not exists. so There is no change." << '\n';
			return false;
		}
		return this->next->addNodeAfterNode(data, afterTarget);
	}

	bool removeNode(T data) {
		if (this->data == data) {
			Node<T>* tmpNext = this->next;
			Node<T>* tmpPre = this->pre;
			
			tmpPre->next = tmpNext;
			if(tmpNext != nullptr) tmpNext->pre = tmpPre;

			cout << "data (" << data << ") will be delete." << '\n';

			delete this;

			return true;
		}
		if (this->next == nullptr) return false;
		return this->next->removeNode(data);
	}

	void print() {
		if (this->next == nullptr) {
			cout << this->data << '\n';
			return;
		}
		cout << this->data << " -> ";
		this->next->print();
	}
};

int main() {

	/* int type example */
	cout << "Int example.." << '\n';
	Node<int>* root = new Node<int>(0);
	root->addNode(1);
	root->addNode(5);
	root->addNodeAfterNode(3, 1);
	root->print();

	root->removeNode(3);
	root->print();

	root->addNodeAfterNode(1, 2);
	root->print();

	root->addNode(2);
	root->print();

	Node<int>* tmpForDelete1 = root;
	while (tmpForDelete1 != nullptr) {
		Node<int>* deleteNext = tmpForDelete1->getNext();
		delete tmpForDelete1;
		tmpForDelete1 = deleteNext;
	}

	/* string type example */
	cout << '\n' << "string example.." << '\n';
	Node<string>* stringRoot = new Node<string>("Root");
	stringRoot->addNode("newNode1");
	stringRoot->addNode("newNode3");
	stringRoot->print();

	stringRoot->addNodeAfterNode("newNode2", "newNode1");
	stringRoot->print();

	stringRoot->addNodeAfterNode("newNode4", "newNode3");
	stringRoot->print();

	stringRoot->removeNode("newNode1");
	stringRoot->print();

	stringRoot->removeNode("newNode4");
	stringRoot->print();

	Node<string>* tmpForDelete2 = stringRoot;
	while (tmpForDelete2 != nullptr) {
		Node<string>* deleteNext = tmpForDelete2->getNext();
		delete tmpForDelete2;
		tmpForDelete2 = deleteNext;
	}

	return 0;
}
