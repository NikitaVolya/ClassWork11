
#pragma once

#include <iostream>

template <typename T>
struct Node
{
	T value;
	Node<T>* next;
};

template <typename T>
class Stack
{
private:
	Node<T>* head;
	size_t lenght;
public:
	Stack() : head(nullptr), lenght(0) {};
	Stack(const std::initializer_list<T>& elements);
	~Stack();

	void push(const T& value);
	void pop();

	bool empty() const { return !head; }
	T& top() { if (head) return head; }
	size_t size() const { return lenght; };
};

template<typename T>
inline Stack<T>::Stack(const std::initializer_list<T>& elements) : Stack()
{
	for (int i = elements.size() - 1; i >= 0; i--)
		push(elements[i]);
}

template<typename T>
Stack<T>::~Stack()
{
	Node<T>* pointer = head;
	while (pointer != nullptr)
	{
		Node<T>* tmp = pointer;
		pointer = tmp->next;
		delete tmp;
	}
}

template<typename T>
void Stack<T>::push(const T& value)
{
	head = new Node<T>{ value, head };
	lenght++;
}

template<typename T>
inline void Stack<T>::pop()
{
	if (!head)
		return;

	Node<T>* tmp = head;
	head = head->next;

	delete tmp;
	lenght--;
}