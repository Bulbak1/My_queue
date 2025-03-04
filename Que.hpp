#include <iostream>

using namespace std;

template <typename T>
class Que {
protected:
	struct Node {
		T value;
		Node* prev = nullptr;
		Node() = default;
		Node(T nval) : value(nval) {};
		~Node() = default;
	};
	Node* first = nullptr;
	Node* last = nullptr;
	int size = 0;
public:
	Que() = default;
	Que(const T&);
	~Que();
	void push(const T&);
	T pop();
	T ctop();
	int size_();
};

template <typename T>
Que<T>::Que(const T& nval) : first(new Node(nval)), last(first), size(1) {

}

template <typename T>
Que<T>::~Que() {
	while (size != 0) {
		pop();
	}
}

template <typename T>
void Que<T>::push(const T& nval) {
	Node* NNode = new Node(nval);
	if (size == 0) {
		first = last = NNode;
	}
	else {
		last->prev = NNode;
		last = NNode;
	}
	size++;
}

template <typename T>
T Que<T>::pop() {
	if (size == 0) {
		throw runtime_error("Очередь пуста, удаление невозможно");
	}
	T value_ = first->value;
	first = first->prev;
	size--;
	return value_;
}

template <typename T>
T Que<T>::ctop() {
	if (size == 0) {
		throw runtime_error("Нельзя вывести элемент т.к. очередь пуста");
	}
	return first->value;
}

template <typename T>
int Que<T>::size_() {
	return size;
}