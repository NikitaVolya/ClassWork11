
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
	size_t size;
public:
	Stack() : head(nullptr), size(0) {};
	Stack(const std::initializer_list<T>& elements);
	~Stack();

	void push(const T& value);
	void pop();

	bool empty() const { return head == nullptr; }
	T& top() { return head->value; }
	const T& top() const { return head->value; }
	size_t getSize() const { return size; };
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
	size++;
}

template<typename T>
inline void Stack<T>::pop()
{
	if (!head)
		return;

	Node<T>* tmp = head;
	head = head->next;

	delete tmp;
	size--;
}