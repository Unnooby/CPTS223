#ifndef LIST_HPP
#define LIST_HPP

#include "node.hpp"
#include <iostream>

template <typename T>
class List {

private:
	Node<T>* head;
public:
	List();
	~List();
	void insertAtFront(const T& value);
	bool removeNode(const std::string& key);
	void display() const;
	Node<T>* begin();
};


template <typename T>
List<T>::List() : head(nullptr) {}

template <typename T>
List<T>::~List() {
	while (head) {
		Node<T>* temp = head;
		head = head->next;
		delete temp;
	}
}

template <typename T>
void List<T>::insertAtFront(const T& value) {
	Node<T>* newNode = new Node<T>(value);
	newNode->next = head;
	head = newNode;
}

template <typename T>
bool List<T>::removeNode(const std::string& key) {
	Node<T>* current = head;
	Node<T>* prev = nullptr;
	while (current)
	{
		if (current->data.key == key)
		{
			if (prev)
			{
				prev->next = current->next;
			}
			else {
				head = current->next;
			}
			delete current;
			return true;
		}
		prev = current;
		current = current->next;

	}
	return false;
}

template <typename T>
void List<T>::display() const {
	Node<T>* temp = head;
	while (temp)
	{
		std::cout << temp->data.key << " - " << temp->data.value << std::endl;
		temp = temp->next;
	}
}

template <typename T>
Node<T>* List<T>::begin() {
	return head;
}
#endif